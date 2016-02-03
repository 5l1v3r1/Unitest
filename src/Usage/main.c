/*
Unitest Usage - How to use Unittest framework
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
#include <stdlib.h>
#include <stdio.h>
#include "Unitest.h"

TEST_METHOD(TestMethod1)
{
	//test code
	//for ex. AssertIsTrue(Boolean);
	printf("Test Method 1\n");
}

TEST_METHOD(TestMethod2)
{
	//test code
	//for ex. AssertIsTrue(Boolean);
	printf("Test Method 2\n");
}

int main(int argc, char **argv)
{
	TEST_GROUP *tGroup;
	tGroup = group_create("TestGroup1");
	group_add_test(tGroup, TestMethod1);
	group_add_test(tGroup, TestMethod2);
	group_run_all(tGroup);
	group_free(tGroup);
	
	return EXIT_SUCCESS;
}
