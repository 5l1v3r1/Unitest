#pragma once

/*
Unitest - Unit Testing Framework for C
Copyright (C) 2016  @maldevel

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <windows.h>

#define STD_OUT GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute(STD_OUT, 0x000c);
#define GREEN SetConsoleTextAttribute(STD_OUT, 0x0002);
#define GOLD SetConsoleTextAttribute(STD_OUT,0x0006);

void Start_Coloring(CONSOLE_SCREEN_BUFFER_INFO *pcsbi);
void Stop_Coloring(CONSOLE_SCREEN_BUFFER_INFO csbi);
