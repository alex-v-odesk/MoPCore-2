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

#ifndef SF_MAPREFERENCE_H
#define SF_MAPREFERENCE_H

#include "Reference.h"
#include "Map.h"

class MapReference : public Reference<Map, Player>
{
    protected:
        void targetObjectBuildLink()
        {
            // called from link()
            getTarget()->m_mapRefManager.insertFirst(this);
            getTarget()->m_mapRefManager.incSize();
        }
        void targetObjectDestroyLink()
        {
            // called from unlink()
            if (isValid()) getTarget()->m_mapRefManager.decSize();
        }
        void sourceObjectDestroyLink()
        {
            // called from invalidate()
            getTarget()->m_mapRefManager.decSize();
        }
    public:
        MapReference() : Reference<Map, Player>() { }
        ~MapReference() { unlink(); }
        MapReference* next() { return (MapReference*)Reference<Map, Player>::next(); }
        MapReference const* next() const { return (MapReference const*)Reference<Map, Player>::next(); }
        MapReference* nockeck_prev() { return (MapReference*)Reference<Map, Player>::nocheck_prev(); }
        MapReference const* nocheck_prev() const { return (MapReference const*)Reference<Map, Player>::nocheck_prev(); }
};
#endif
