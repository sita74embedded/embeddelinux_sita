#include<stdio.h>
#define SIZE(p)  (char*)(&p+1)-(char*)(&p)

int main()
{
	int a;
	char b;
	float f;
	double d;

	printf("size of int is %ld\n",SIZE(a));
	printf("size of char is %ld\n",SIZE(b));
	printf("size of float is %ld\n",SIZE(f));
	printf("size of double is %ld\n",SIZE(d));
}
