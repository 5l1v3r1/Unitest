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

#include "Unitest.h"


static bool _list_grow(List * list)
{
	if (list->num_elements >= list->max_elements)
	{
		list->max_elements *= GROW;
		if (!(list->data = (void **)arealloc(list->data, list->max_elements * sizeof(list->data[0]))))
			return false;
	}

	return true;
}


List *list_create(void)
{
	List *list;

	if (!(list = (List *)amalloc(sizeof(List)))) return NULL;
	list->num_elements = 0;
	list->max_elements = LIMIT;
	list->current = list->last = -1;

	if (!(list->data = (void **)amalloc(sizeof(list->data[0]) * LIMIT))) {
		afree(list);
		return NULL;
	}

	return list;
}


void list_add(List *list, void *p)
{
	if (list == NULL) return;

	if (!_list_grow(list)) return;

	list->last++;
	list->num_elements++;
	list->current = list->last;
	list->data[list->current] = p;
}


TEST_GROUP *group_create(const char *name)
{
	TEST_GROUP *tGroup;
	if (!(tGroup = (TEST_GROUP *)amalloc(sizeof(TEST_GROUP)))) return NULL;

	if (name == NULL)
		tGroup->name = "";
	else
		tGroup->name = name;

	if (!(tGroup->methods = list_create())) {
		afree(tGroup);
		return NULL;
	}

	return tGroup;
}


void group_add_test(TEST_GROUP *tGroup, TMethod tMethod)
{
	if (tGroup == NULL || tMethod == NULL)
		return;

	list_add(tGroup->methods, tMethod);
}