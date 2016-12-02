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

#ifndef SF_ACCMGR_H
#define SF_ACCMGR_H

#include "RBAC.h"
#include <ace/Singleton.h>

enum AccountOpResult
{
    AOR_OK,
    AOR_NAME_TOO_LONG,
    AOR_PASS_TOO_LONG,
    AOR_EMAIL_TOO_LONG,
    AOR_NAME_ALREADY_EXIST,
    AOR_NAME_NOT_EXIST,
    AOR_DB_INTERNAL_ERROR
};

enum PasswordChangeSecurity
{
    PW_NONE,
    PW_EMAIL,
    PW_RBAC
};

#define MAX_ACCOUNT_STR 16
#define MAX_EMAIL_STR 64

namespace rbac
{
typedef std::map<uint32, rbac::RBACPermission*> RBACPermissionsContainer;
typedef std::map<uint8, rbac::RBACPermissionContainer> RBACDefaultPermissionsContainer;
}

class AccountMgr
{
    friend class ACE_Singleton<AccountMgr, ACE_Null_Mutex>;

    private:
        AccountMgr();
        ~AccountMgr();

    public:
        AccountOpResult CreateAccount(std::string username, std::string password, std::string email);
        static AccountOpResult DeleteAccount(uint32 accountId);
        static AccountOpResult ChangeUsername(uint32 accountId, std::string newUsername, std::string newPassword);
        static AccountOpResult ChangePassword(uint32 accountId, std::string newPassword);
        static AccountOpResult ChangeEmail(uint32 accountId, std::string newEmail);
        static AccountOpResult ChangeRegEmail(uint32 accountId, std::string newEmail);
        static bool CheckPassword(uint32 accountId, std::string password);
        static bool CheckEmail(uint32 accountId, std::string newEmail);

        static uint32 GetId(std::string const& username);
        static uint32 GetSecurity(uint32 accountId);
        static uint32 GetSecurity(uint32 accountId, int32 realmId);
        static bool GetName(uint32 accountId, std::string& name);
        static bool GetEmail(uint32 accountId, std::string& email);
        static uint32 GetCharactersCount(uint32 accountId);

        static std::string CalculateShaPassHash(std::string const& name, std::string const& password);
        static bool normalizeString(std::string& utf8String);
        static bool IsPlayerAccount(uint32 gmlevel);
        static bool IsAdminAccount(uint32 gmlevel);
        static bool IsConsoleAccount(uint32 gmlevel);
        static bool HasPermission(uint32 accountId, uint32 permission, uint32 realmId);

        void UpdateAccountAccess(rbac::RBACData* rbac, uint32 accountId, uint8 securityLevel, int32 realmId);

        void LoadRBAC();
        rbac::RBACPermission const* GetRBACPermission(uint32 permission) const;

        rbac::RBACPermissionsContainer const& GetRBACPermissionList() const { return _permissions; }
        rbac::RBACPermissionContainer const& GetRBACDefaultPermissions(uint8 secLevel);

    private:
        void ClearRBAC();
        rbac::RBACPermissionsContainer _permissions;
        rbac::RBACDefaultPermissionsContainer _defaultPermissions;
};

#define sAccountMgr ACE_Singleton<AccountMgr, ACE_Null_Mutex>::instance()
#endif
