#include<stdio.h>
#include<stdlib.h>
struct student
{
	char name[20];
	char sec;
	int roll_no;
};
int main()
{
	struct student *str;
	str=(struct student*)malloc(sizeof(struct student));
	if(str==NULL)
	{
		printf("Memory not allocated\n");
		return 1;
	}
	printf("Enter the student name:::\n ");
	scanf("%[^\n]",str->name);
	getchar();
	printf("Enter the section\n");
	scanf("%c",&str->sec);
	printf("Enter the roll_no\n");
	scanf("%d",&str->roll_no);

	printf("name = %s\n sec = %c\n roll_no = %d\n",str->name,str->sec,str->roll_no);
}

