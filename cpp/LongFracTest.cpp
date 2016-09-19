
#include <stdio.h>
#include "LongFrac.h"

void test_add()
{
	printf("test_add\n");
	LongFrac a=1,b=2;
	
	a/=3;
	b/=3;
	a += b;
	a.print();
	a+=b;
	a.print();
}

void test_sub()
{
	printf("test_sub\n");
    LongFrac  a=1, b=1;
    b /= 7;
    b.print();
    a -= b;
    a.print();
}

void test_mul()
{
	printf("test_mul\n");
	LongFrac a=1;
	a/=7;
	a.print();
	a*=7;
	a.print();
}

void test_div()
{
	printf("test_div\n");
	LongFrac a=1;
	a/=2;
	a.print();
	a/=3;
	a.print();
}

void test_atan()
{
	printf("test_atan\n");
	LongFrac a=atan_inverse(5);
	a.print();
}

int main()
{
	test_add();
	test_sub();
	test_mul();
	test_div();
	test_atan();
}

