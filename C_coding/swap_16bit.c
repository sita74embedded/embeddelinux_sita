#include<stdio.h>
int main()
{
	unsigned int num=0x1234;
	unsigned int swap=(num>>8)|(num<<8);
	printf("0x%X\n",swap);
	printf("0x%X\n",num);
}

