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

#define WIN32_LEAN_AND_MEAN

#include "Common.h"
#include <stdbool.h>

#define TEST_METHOD(methodName) static void methodName(void)

//represents a test method
typedef void(*TMethod) (void);

enum
{
	LIMIT = 1,
	GROW = 2
};

typedef struct List
{
	unsigned int num_elements;
	unsigned int max_elements;
	int current;
	int last;
	void **data;
}List, *PList;


//a group of test methods
typedef struct TEST_GROUP
{
	const char *name;
	List *methods;
}TEST_GROUP, *PTEST_GROUP;


//list
List *list_create(void);

void list_add(List *list, void *p);

void list_front(List * list);

bool list_at_end(List * list);

void list_advance(List * list);

void *list_val(List * list);

void list_free(List * list);


//group
TEST_GROUP *group_create(const char *name);

void group_add_test(TEST_GROUP *tGroup, TMethod tMethod);

void group_run_all(TEST_GROUP *tGroup);

void group_free(TEST_GROUP *tGroup);
