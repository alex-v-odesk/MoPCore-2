/* MoPCore is a World of Warcarft server for
 * game build 5.4.8. 
 *
 * Copyright (C) 2008-2016 JustACore.
 * Copyright (C) 2008-2016 TrinityCore.
 * Copyright (C) 2011-2016 ProjectSkyFire.
 * Copyright (C) 2005-2016 MaNGOS.
 * Copyright (C) 2006-2009 ScriptDev2.
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

/* ScriptData
SDName: Sunken_Temple
SD%Complete: 100
SDComment: Area Trigger + Puzzle event support
SDCategory: Sunken Temple
EndScriptData */

/* ContentData
at_malfurion_Stormrage_trigger
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "sunken_temple.h"
#include "Player.h"

/*#####
# at_malfurion_Stormrage_trigger
#####*/

class at_malfurion_stormrage : public AreaTriggerScript
{
public:
    at_malfurion_stormrage() : AreaTriggerScript("at_malfurion_stormrage") { }

    bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/) OVERRIDE
    {
        if (player->GetInstanceScript() && !player->FindNearestCreature(15362, 15))
            player->SummonCreature(15362, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), -1.52f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 100000);
        return false;
    }

};
/*#####
# go_atalai_statue
#####*/

class go_atalai_statue : public GameObjectScript
{
public:
    go_atalai_statue() : GameObjectScript("go_atalai_statue") { }

    bool OnGossipHello(Player* player, GameObject* go) OVERRIDE
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            instance->SetData(EVENT_STATE, go->GetEntry());
        return false;
    }

};

void AddSC_sunken_temple()
{
    new at_malfurion_stormrage();
    new go_atalai_statue();
}
