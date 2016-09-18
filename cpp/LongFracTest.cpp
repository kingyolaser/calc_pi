
#include <stdio.h>
#include "LongFrac.h"

void test_add()
{
	printf("test_add\n");
	LongFrac a=1,b=2;
	
	a += b;
	a.print();
}

void test_sub()
{
	printf("test_sub\n");
    LongFrac  a=1, b=2;
    a /= 3;
    a.print();
    b /= 7;
    b.print();
    a -= b;
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

int main()
{
	test_add();
	test_sub();
	test_div();
}

