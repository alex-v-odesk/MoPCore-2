/* MoPCore is a World of Warcarft server for
 * game build 5.4.8. 
 *
 * Copyright (C) 2008-2016 JustACore.
 * Copyright (C) 2008-2016 TrinityCore.
 * Copyright (C) 2011-2016 ProjectSkyFire.
 * Copyright (C) 2005-2016 MaNGOS.
 *
 * ==== Start of GNU GPL ====
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * ==== End of GNU GPL ====
 */

#ifndef TRINITY_FLEEINGMOVEMENTGENERATOR_H
#define TRINITY_FLEEINGMOVEMENTGENERATOR_H

#include "MovementGenerator.h"

template<class T>
class FleeingMovementGenerator : public MovementGeneratorMedium< T, FleeingMovementGenerator<T> >
{
    public:
        FleeingMovementGenerator(uint64 fright) : i_frightGUID(fright), i_nextCheckTime(0) { }

        void DoInitialize(T*);
        void DoFinalize(T*);
        void DoReset(T*);
        bool DoUpdate(T*, uint32);

        MovementGeneratorType GetMovementGeneratorType() { return FLEEING_MOTION_TYPE; }

    private:
        void _setTargetLocation(T*);
        void _getPoint(T*, float &x, float &y, float &z);

        uint64 i_frightGUID;
        TimeTracker i_nextCheckTime;
};

class TimedFleeingMovementGenerator : public FleeingMovementGenerator<Creature>
{
    public:
        TimedFleeingMovementGenerator(uint64 fright, uint32 time) :
            FleeingMovementGenerator<Creature>(fright),
            i_totalFleeTime(time) { }

        MovementGeneratorType GetMovementGeneratorType() { return TIMED_FLEEING_MOTION_TYPE; }
        bool Update(Unit*, uint32);
        void Finalize(Unit*);

    private:
        TimeTracker i_totalFleeTime;
};

#endif
