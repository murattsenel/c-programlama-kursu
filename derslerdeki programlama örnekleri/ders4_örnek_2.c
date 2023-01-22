#include <stdio.h>


void func(void)
{
	int x = 10;
	printf("x = %d \n",x);
	x+=10;
}

int main(void)
{
 func();
 func();
 func();
 func();
}
