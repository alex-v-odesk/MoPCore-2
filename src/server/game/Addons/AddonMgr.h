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

#ifndef SF_ADDONMGR_H
#define SF_ADDONMGR_H

#include "Define.h"
#include <string>
#include <list>

struct AddonInfo
{
    AddonInfo(const std::string& name, uint8 enabled, uint32 crc, uint8 state, bool crcOrPubKey)
        : Name(name), Enabled(enabled), CRC(crc), State(state), UsePublicKeyOrCRC(crcOrPubKey)
        { }

    std::string Name;
    uint8 Enabled;
    uint32 CRC;
    uint8 State;
    bool UsePublicKeyOrCRC;
};

struct SavedAddon
{
    SavedAddon(std::string const& name, uint32 crc) : Name(name)
    {
        CRC = crc;
    }

    std::string Name;
    uint32 CRC;
};

struct BannedAddon
{
    uint32 Id;
    uint8 NameMD5[16];
    uint8 VersionMD5[16];
    uint32 Timestamp;
};

#define STANDARD_ADDON_CRC 0x4C1C776D

namespace AddonMgr
{
    void LoadFromDB();
    void SaveAddon(AddonInfo const& addon);
    SavedAddon const* GetAddonInfo(const std::string& name);

    typedef std::list<BannedAddon> BannedAddonList;
    BannedAddonList const* GetBannedAddons();
}

#endif
