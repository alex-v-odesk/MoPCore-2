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

/* ScriptData
Name: achievement_commandscript
%Complete: 100
Comment: All achievement related commands
Category: commandscripts
EndScriptData */

#include "AchievementMgr.h"
#include "Guild.h"
#include "Chat.h"
#include "Language.h"
#include "Player.h"
#include "ScriptMgr.h"

class achievement_commandscript : public CommandScript
{
public:
    achievement_commandscript() : CommandScript("achievement_commandscript") { }

    ChatCommand* GetCommands() const OVERRIDE
    {
        static ChatCommand achievementCommandTable[] =
        {
            { "add", rbac::RBAC_PERM_COMMAND_ACHIEVEMENT_ADD, false, &HandleAchievementAddCommand, "", NULL },
            { NULL, 0, false, NULL, "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "achievement", rbac::RBAC_PERM_COMMAND_ACHIEVEMENT,  false, NULL, "", achievementCommandTable },
            { NULL, 0, false, NULL, "", NULL }
        };
        return commandTable;
    }

    static bool HandleAchievementAddCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 achievementId = atoi((char*)args);
        if (!achievementId)
        {
            if (char* id = handler->extractKeyFromLink((char*)args, "Hachievement"))
                achievementId = atoi(id);
            if (!achievementId)
                return false;
        }

        Player* target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(achievementId))
        {
            if (achievementEntry->flags & ACHIEVEMENT_FLAG_GUILD)
            {
                if (Guild* guild = target->GetGuild())
                    guild->GetAchievementMgr().CompletedAchievement(achievementEntry, target);
            } else
                target->CompletedAchievement(achievementEntry);
        }

        return true;
    }
};

void AddSC_achievement_commandscript()
{
    new achievement_commandscript();
}
