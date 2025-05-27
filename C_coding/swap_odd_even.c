#include<stdio.h>
int main()
{
	int num=0x12;
	int even_extract=0x55;
	int odd_extract=0xAA;
	int even=num & even_extract;
	int odd=num & odd_extract;
	even<<=1;
	odd>>=1;
	int after_swap=even | odd;
	printf("original 0x%X\n",num);
	printf("after swap 0x%X\n",after_swap);
}
