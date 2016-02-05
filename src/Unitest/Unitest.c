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
	if (list == NULL)
		return false;

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

	if (!(list = (List *)amalloc(sizeof(List))))
		return NULL;

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


void list_front(List * list)
{
	if (list == NULL) return;

	if (list->current == -1)
		return;

	list->current = 0;
}


bool list_at_end(List * list)
{
	if (list == NULL)
		return true;

	if (list->current == -1)
		return true;
	else
		return (list->current > list->last);
}


void list_advance(List * list)
{
	if (list == NULL)
		return;

	if (list_at_end(list))
		return;

	list->current++;
}


void *list_val(List * list)
{
	if (list == NULL)
		return NULL;

	if (list->current == -1 || list->current > list->last)
		return NULL;

	return list->data[list->current];
}


void list_free(List * list)
{
	if (list == NULL)
		return;

	afree(list->data);
	afree(list);
}


TEST_GROUP *group_create(const char *name)
{
	TEST_GROUP *tGroup;

	if (!(tGroup = (TEST_GROUP *)amalloc(sizeof(TEST_GROUP))))
		return NULL;

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


void _group_add_test(TEST_GROUP *tGroup, TFunction tFunction, const char *fName)
{
	TMethod *tMethod;

	if (tGroup == NULL || tFunction == NULL)
		return;

	if (!(tMethod = (TMethod *)amalloc(sizeof(TMethod))))
		return;

	tMethod->name = fName;
	tMethod->function = tFunction;

	list_add(tGroup->methods, tMethod);
}


void group_run_all(TEST_GROUP *tGroup)
{
	List *methods;
	TMethod *tMethod;

	if (tGroup == NULL || tGroup->methods == NULL)
		return;

	methods = tGroup->methods;

	for (list_front(methods); !list_at_end(methods); list_advance(methods))
	{
		tMethod = (TMethod*)list_val(methods);
		printf("\n--[[ %s: %s\n", tGroup->name, tMethod->name);
		tMethod->function();
	}
}


void group_free(TEST_GROUP *tGroup)
{
	List *methods;
	TMethod *tMethod;

	if (tGroup == NULL)
		return;

	methods = tGroup->methods;
	for (list_front(methods); !list_at_end(methods); list_advance(methods))
	{
		tMethod = (TMethod*)list_val(methods);
		afree(tMethod);
	}

	list_free(tGroup->methods);

	afree(tGroup);
}


void _assert_failed(const char *msg, ...)
{
	va_list valist;
	char buf[BUFSIZ];

	va_start(valist, msg);
	vsnprintf_s(buf, BUFSIZ, _TRUNCATE, msg, valist);
	printf("[FAILURE] %s\n", buf);

	va_end(valist);
}


void _assert_succeeded(const char *msg, ...)
{
	va_list valist;
	char buf[BUFSIZ];

	va_start(valist, msg);
	vsnprintf_s(buf, BUFSIZ, _TRUNCATE, msg, valist);
	printf("[SUCCESS] %s\n", buf);

	va_end(valist);
}
