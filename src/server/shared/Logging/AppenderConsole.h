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

#ifndef APPENDERCONSOLE_H
#define APPENDERCONSOLE_H

#include "Appender.h"
#include <string>

enum ColorTypes
{
    BLACK,
    RED,
    GREEN,
    BROWN,
    BLUE,
    MAGENTA,
    CYAN,
    GREY,
    YELLOW,
    LRED,
    LGREEN,
    LBLUE,
    LMAGENTA,
    LCYAN,
    WHITE
};

const uint8 MaxColors = uint8(WHITE) + 1;

class AppenderConsole: public Appender
{
    public:
        AppenderConsole(uint8 _id, std::string const& name, LogLevel level, AppenderFlags flags);
        void InitColors(const std::string& init_str);

    private:
        void SetColor(bool stdout_stream, ColorTypes color);
        void ResetColor(bool stdout_stream);
        void _write(LogMessage const& message);
        bool _colored;
        ColorTypes _colors[MaxLogLevels];
};

#endif
