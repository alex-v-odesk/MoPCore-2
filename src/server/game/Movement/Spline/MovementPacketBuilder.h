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

#ifndef TRINITYSERVER_PACKET_BUILDER_H
#define TRINITYSERVER_PACKET_BUILDER_H

#include "Define.h" // for uint32
#include "Unit.h"
#include "G3D/Vector3.h"
using G3D::Vector3;

class ByteBuffer;
class WorldPacket;

namespace Movement
{
    enum MonsterMoveType
    {
        MonsterMoveNormal       = 0,
        MonsterMoveStop         = 1,
        MonsterMoveFacingPoint  = 2,
        MonsterMoveFacingTarget = 3,
        MonsterMoveFacingAngle  = 4
    };

    class MoveSpline;
    class PacketBuilder
    {
    public:

        static void WriteMonsterMove(const MoveSpline& mov, WorldPacket& data, Unit* unit);
        static void WriteStopMovement(Vector3 const& loc, uint32 splineId, ByteBuffer& data, Unit* unit);
        static void WriteCreateBits(MoveSpline const& moveSpline, ByteBuffer& data);
        static void WriteCreateData(MoveSpline const& moveSpline, ByteBuffer& data);
        static void WriteFacingTargetPart(MoveSpline const& moveSpline, ByteBuffer& data);
        static MonsterMoveType GetMonsterMoveType(MoveSpline const& moveSpline);
    };
}
#endif // TRINITYSERVER_PACKET_BUILDER_H
