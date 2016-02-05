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

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

#define SUCCESS	1
#define FAILURE	0

#define afree(x) if(x) { free(x); x=NULL; }
#define azero(x, size) if(x && size>0) memset(x, 0, size);

void *amalloc(size_t size);
void* arealloc(void *mem, size_t size);
