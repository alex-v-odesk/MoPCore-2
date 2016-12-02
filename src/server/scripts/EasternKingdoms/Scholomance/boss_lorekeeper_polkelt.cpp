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

/*
Name: Boss_Lorekeeper_Polkelt
%Complete: 100
Comment:
Category: Scholomance
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "scholomance.h"

enum Spells
{
    SPELL_VOLATILEINFECTION     = 24928,
    SPELL_DARKPLAGUE            = 18270,
    SPELL_CORROSIVEACID         = 23313,
    SPELL_NOXIOUSCATALYST       = 18151
};

enum Events
{
    EVENT_VOLATILEINFECTION     = 1,
    EVENT_DARKPLAGUE            = 2,
    EVENT_CORROSIVEACID         = 3,
    EVENT_NOXIOUSCATALYST       = 4
};

class boss_lorekeeper_polkelt : public CreatureScript
{
    public: boss_lorekeeper_polkelt() : CreatureScript("boss_lorekeeper_polkelt") { }

        struct boss_lorekeeperpolkeltAI : public BossAI
        {
            boss_lorekeeperpolkeltAI(Creature* creature) : BossAI(creature, DATA_LOREKEEPERPOLKELT) { }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_VOLATILEINFECTION, 38000);
                events.ScheduleEvent(EVENT_DARKPLAGUE, 8000);
                events.ScheduleEvent(EVENT_CORROSIVEACID, 45000);
                events.ScheduleEvent(EVENT_NOXIOUSCATALYST, 35000);
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
                        case EVENT_VOLATILEINFECTION:
                            DoCastVictim(SPELL_VOLATILEINFECTION, true);
                            events.ScheduleEvent(EVENT_VOLATILEINFECTION, 32000);
                            break;
                        case EVENT_DARKPLAGUE:
                            DoCastVictim(SPELL_DARKPLAGUE, true);
                            events.ScheduleEvent(EVENT_DARKPLAGUE, 8000);
                            break;
                        case EVENT_CORROSIVEACID:
                            DoCastVictim(SPELL_CORROSIVEACID, true);
                            events.ScheduleEvent(EVENT_CORROSIVEACID, 25000);
                            break;
                        case EVENT_NOXIOUSCATALYST:
                            DoCastVictim(SPELL_NOXIOUSCATALYST, true);
                            events.ScheduleEvent(EVENT_NOXIOUSCATALYST, 38000);
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
            return new boss_lorekeeperpolkeltAI(creature);
        }
};

void AddSC_boss_lorekeeperpolkelt()
{
    new boss_lorekeeper_polkelt();
}
