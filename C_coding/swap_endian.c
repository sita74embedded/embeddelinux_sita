#include<stdio.h>
unsigned int swap( unsigned int num)
{
	return(((num>>24)&(0x000000FF))|
		((num>>8)&(0x0000FF00))|
		((num<<8)&(0x00FF0000))|
		((num<<24)&(0xFF000000)));	
}	
int main()
{
	unsigned int a = 0x12345678;
	unsigned int swap_after=swap(a);
	printf("0x%X \n",swap_after);
}

