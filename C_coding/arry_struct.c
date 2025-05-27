#include<stdio.h>
#include<stdlib.h>
struct student
{
	char name[50];
	int roll_no;
	char sec;
};

int main()
{
	struct student stu[100];
	
	int n,i;
	printf("Enter the value of n\n ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		getchar();
		printf("Enter the student name\n");
		scanf("%[^\n]",stu[i].name);
		getchar();
		printf("Enter the roll number\n");
		scanf("%d",&stu[i].roll_no);
		getchar();
		printf("Enter the section\n ");
		scanf("%c",&stu[i].sec);
	}
	for(i=0;i<n;i++)
	{
		printf("name :: %s\n",stu[i].name);
		printf("roll_no :: %d\n",stu[i].roll_no);
		printf("sec :: %c\n",stu[i].sec);
	}
}


