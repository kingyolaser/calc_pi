
#include "LongFrac.h"

void test_add()
{
	LongFrac a=1,b=2;
	
	a += b;
	a.print();
}

void test_div()
{
	LongFrac a=1;
	a/=2;
	a.print();
	a/=3;
	a.print();
}

int main()
{
	test_add();
	test_div();
}

