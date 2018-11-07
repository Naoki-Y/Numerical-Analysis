#include <stdio.h>

#define SWAP(type,a,b) { type temp = a; a = b; b = temp; }

int main(void)
{
	int a = 10,b = 100;
	printf("a = %3d : b = %3d\n",a,b);
	a^=b^=a^=b;
	printf("a = %3d : b = %3d\n",a,b);
	return 0;
}