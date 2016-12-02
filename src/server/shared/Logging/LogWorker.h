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

#ifndef LOGWORKER_H
#define LOGWORKER_H

#include "LogOperation.h"

#include <ace/Task.h>
#include <ace/Activation_Queue.h>

class LogWorker: protected ACE_Task_Base
{
    public:
        LogWorker();
        ~LogWorker();

        typedef ACE_Message_Queue_Ex<LogOperation, ACE_MT_SYNCH> LogMessageQueueType;

        enum
        {
            HIGH_WATERMARK = 8 * 1024 * 1024,
            LOW_WATERMARK  = 8 * 1024 * 1024
        };

        int enqueue(LogOperation *op);

    private:
        virtual int svc();
        LogMessageQueueType m_queue;
};

#endif
