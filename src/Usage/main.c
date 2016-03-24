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
#include <string.h>

TEST_METHOD(TestMethod1)
{
	//test code
	int xxx = 100;
	double zzz = 21.00012345;
	const char *aaa = "test000";
	bool xyz = true;
	char www[10] = { 0 };
	double nnn = -5.2;
	const char *x1 = "aa";
	const char *x2 = "ab";

	AssertAreEqual_int(xxx, 101);
	AssertAreNotEqual_int(xxx, 101);
	AssertLessThan_int(xxx, 0);
	AssertLessEqual_int(xxx, 0);
	AssertGreaterThan_int(xxx, 0);
	AssertGreaterEqual_int(xxx, 0);

	AssertAreEqual_double(zzz, 21.100123);
	AssertAreNotEqual_double(zzz, 21.100123);
	AssertLessThan_double(nnn, 0.0);
	AssertLessEqual_double(nnn, 0.0);
	AssertGreaterThan_double(nnn, 0.0);
	AssertGreaterEqual_double(nnn, 0.0);

	AssertAreEqual_str(aaa, "test111");
	AssertAreNotEqual_str(aaa, "test111");
	AssertLessThan_str(x1, x2);
	AssertLessEqual_str(x1, x2);
	AssertGreaterThan_str(x1, x2);
	AssertGreaterEqual_str(x1, x2);

	AssertIsTrue(xyz);
	AssertIsFalse(xyz);

	AssertIsNull(www);
	AssertIsNotNull(www);
}

TEST_METHOD(TestMethod2)
{
	//test code
	int yyy = 101;
	double zzz = 22.00012345;
	const char *ccc = "test222";
	bool zxc = false;
	char *ttt = NULL;
	int xxx = -1;
	double nnn = 2.0;
	const char *x1 = "cc";
	const char *x2 = "bb";

	AssertAreEqual_int(yyy, 101);
	AssertAreNotEqual_int(yyy, 101);
	AssertLessThan_int(xxx, 0);
	AssertLessEqual_int(xxx, 0);
	AssertGreaterThan_int(xxx, 0);
	AssertGreaterEqual_int(xxx, 0);

	AssertAreEqual_double(zzz, 22.00012345);
	AssertAreNotEqual_double(zzz, 22.00012345);
	AssertLessThan_double(nnn, 0.0);
	AssertLessEqual_double(nnn, 0.0);
	AssertGreaterThan_double(nnn, 0.0);
	AssertGreaterEqual_double(nnn, 0.0);

	AssertAreEqual_str(ccc, "test222");
	AssertAreNotEqual_str(ccc, "test222");
	AssertLessThan_str(x1, x2);
	AssertLessEqual_str(x1, x2);
	AssertGreaterThan_str(x1, x2);
	AssertGreaterEqual_str(x1, x2);

	AssertIsTrue(zxc);
	AssertIsFalse(zxc);

	AssertIsNull(ttt);
	AssertIsNotNull(ttt);
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
