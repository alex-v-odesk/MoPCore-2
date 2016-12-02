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

#ifndef DEF_MAGISTERS_TERRACE_H
#define DEF_MAGISTERS_TERRACE_H

#define ERROR_INST_DATA      "TSCR Error: Instance Data not set properly for Magister's Terrace instance (map 585). Encounters will be buggy."

enum Data
{
    DATA_SELIN_EVENT,
    DATA_VEXALLUS_EVENT,
    DATA_DELRISSA_EVENT,
    DATA_KAELTHAS_EVENT,

    DATA_SELIN,
    DATA_FEL_CRYSTAL,
    DATA_FEL_CRYSTAL_SIZE,

    DATA_VEXALLUS_DOOR,
    DATA_DELRISSA,
    DATA_DELRISSA_DOOR,

    DATA_KAEL_DOOR,
    DATA_KAEL_STATUE_LEFT,
    DATA_KAEL_STATUE_RIGHT,

    DATA_DELRISSA_DEATH_COUNT,
    DATA_KAELTHAS_STATUES,
    DATA_ESCAPE_ORB
};

#endif
