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
 * ====
 */

/* ScriptData
SDName: Boss_Lucifron
SD%Complete: 100
SDComment:
SDCategory: Molten Core
EndScriptData */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "molten_core.h"

enum Spells
{
    SPELL_IMPENDING_DOOM    = 19702,
    SPELL_LUCIFRON_CURSE    = 19703,
    SPELL_SHADOW_SHOCK      = 20603,
};

enum Events
{
    EVENT_IMPENDING_DOOM    = 1,
    EVENT_LUCIFRON_CURSE    = 2,
    EVENT_SHADOW_SHOCK      = 3,
};

class boss_lucifron : public CreatureScript
{
    public:
        boss_lucifron() : CreatureScript("boss_lucifron") { }

        struct boss_lucifronAI : public BossAI
        {
            boss_lucifronAI(Creature* creature) : BossAI(creature, BOSS_LUCIFRON)
            {
            }

            void EnterCombat(Unit* victim) OVERRIDE
            {
                BossAI::EnterCombat(victim);
                events.ScheduleEvent(EVENT_IMPENDING_DOOM, 10000);
                events.ScheduleEvent(EVENT_LUCIFRON_CURSE, 20000);
                events.ScheduleEvent(EVENT_SHADOW_SHOCK, 6000);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_IMPENDING_DOOM:
                            DoCastVictim(SPELL_IMPENDING_DOOM);
                            events.ScheduleEvent(EVENT_IMPENDING_DOOM, 20000);
                            break;
                        case EVENT_LUCIFRON_CURSE:
                            DoCastVictim(SPELL_LUCIFRON_CURSE);
                            events.ScheduleEvent(EVENT_LUCIFRON_CURSE, 15000);
                            break;
                        case EVENT_SHADOW_SHOCK:
                            DoCastVictim(SPELL_SHADOW_SHOCK);
                            events.ScheduleEvent(EVENT_SHADOW_SHOCK, 6000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_lucifronAI(creature);
        }
};

void AddSC_boss_lucifron()
{
    new boss_lucifron();
}