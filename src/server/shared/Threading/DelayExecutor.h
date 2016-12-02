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
 
#ifndef _M_DELAY_EXECUTOR_H
#define _M_DELAY_EXECUTOR_H

#include <ace/Task.h>
#include <ace/Activation_Queue.h>
#include <ace/Method_Request.h>

class DelayExecutor : protected ACE_Task_Base
{
    public:

        DelayExecutor();
        virtual ~DelayExecutor();

        static DelayExecutor* instance();

        int execute(ACE_Method_Request* new_req);

        int start(int num_threads = 1, ACE_Method_Request* pre_svc_hook = NULL, ACE_Method_Request* post_svc_hook = NULL);

        int deactivate();

        bool activated();

        virtual int svc();

    private:

        ACE_Activation_Queue queue_;
        ACE_Method_Request* pre_svc_hook_;
        ACE_Method_Request* post_svc_hook_;
        bool activated_;

        void activated(bool s);
};

#endif // _M_DELAY_EXECUTOR_H