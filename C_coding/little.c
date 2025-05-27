#include<stdio.h>
int main()
{
	int a=1;
	char*p=(char*)&a;
	
	for(int i=0;i<sizeof(a);i++)
	{
		printf("Byte %d : %02X\n",i,p[i]&0XFF);
	}

	if(*p==1)
	{
		printf("Littele Endian\n");
	}
	else
	{
		printf("Big Endian\n");
	}
}
