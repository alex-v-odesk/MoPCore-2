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

#include "LFGPlayerData.h"

namespace lfg
{

LfgPlayerData::LfgPlayerData(): m_State(LFG_STATE_NONE), m_OldState(LFG_STATE_NONE),
    m_Team(0), m_Group(0), m_Roles(0), m_Comment("")
{ }

LfgPlayerData::~LfgPlayerData() { }

void LfgPlayerData::SetState(LfgState state)
{
    switch (state)
    {
        case LFG_STATE_NONE:
        case LFG_STATE_FINISHED_DUNGEON:
            m_Roles = 0;
            m_SelectedDungeons.clear();
            m_Comment = "";
            // No break on purpose
        case LFG_STATE_DUNGEON:
            m_OldState = state;
            // No break on purpose
        default:
            m_State = state;
    }
}

void LfgPlayerData::RestoreState()
{
    if (m_OldState == LFG_STATE_NONE)
    {
        m_SelectedDungeons.clear();
        m_Roles = 0;
    }
    m_State = m_OldState;
}

void LfgPlayerData::SetLockedDungeons(LfgLockMap const& lockStatus)
{
    m_LockedDungeons = lockStatus;
}

void LfgPlayerData::SetTeam(uint8 team)
{
    m_Team = team;
}

void LfgPlayerData::SetGroup(uint64 group)
{
    m_Group = group;
}

void LfgPlayerData::SetRoles(uint8 roles)
{
    m_Roles = roles;
}

void LfgPlayerData::SetComment(std::string const& comment)
{
    m_Comment = comment;
}

void LfgPlayerData::SetSelectedDungeons(LfgDungeonSet const& dungeons)
{
    m_SelectedDungeons = dungeons;
}

LfgState LfgPlayerData::GetState() const
{
    return m_State;
}

LfgState LfgPlayerData::GetOldState() const
{
    return m_OldState;
}

const LfgLockMap& LfgPlayerData::GetLockedDungeons() const
{
    return m_LockedDungeons;
}

uint8 LfgPlayerData::GetTeam() const
{
    return m_Team;
}

uint64 LfgPlayerData::GetGroup() const
{
    return m_Group;
}

uint8 LfgPlayerData::GetRoles() const
{
    return m_Roles;
}

std::string const& LfgPlayerData::GetComment() const
{
    return m_Comment;
}

LfgDungeonSet const& LfgPlayerData::GetSelectedDungeons() const
{
    return m_SelectedDungeons;
}

} // namespace lfg