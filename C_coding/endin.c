#include<stdio.h>
int main()
{
	int num=0x12345678;
	int swap=((num>>24)&(0x000000FF))|((num>>8)&(0x0000FF00))|((num<<8)&(0x00FF0000))|((num<<24)&(0xFF000000));
	printf("0X%X",swap);
}

