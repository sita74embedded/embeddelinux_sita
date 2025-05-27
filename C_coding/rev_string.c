#include<stdio.h>
#include<string.h>
char* reverse_string(char*str)
{
	int len=strlen(str);
//	printf("length = %d\n",len);
	int start=0;
	int end=len-1;
//	printf("end=%d\n",end);
	char temp;
	while(start<=end)
	{//	printf("in while\n");
		temp=str[start];
		str[start]=str[end];
		str[end]=temp;

	//	printf("temp=%c\n str[start]=%c\n str[end]=%c\n",temp,str[start],str[end]);

		start++;
		end--;
	}
	return str;

}
int main()
{
	char str[100];
	printf("Enter the string\n");
	scanf("%s",str);
	char*rev=reverse_string(str);
	printf("After reverse the string is %s\n",rev);

}
