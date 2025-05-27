#include<stdio.h>
#include<stdlib.h>
struct student
{
	char name[50];
	int roll_no;
	char sec;
};
struct student* fun_array(struct student array[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter the stdent $$  \n");
		getchar();
		scanf("%[^\n]",array[i].name);
		getchar();
		printf("Enter the roll_no\n");
		scanf("%d",&array[i].roll_no);
		getchar();
		printf("Enter the section\n");
		scanf("%c",&array[i].sec);
	}
	return  array;
	

}
int main()
{
	struct student *stu,*ret;
	stu=(struct student*)malloc(sizeof(struct student));
	struct student array[100];
	int n,i;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	ret=fun_array(array,n);
	for(int i=0;i<n;i++)
	{
		printf("name -> %s\n",ret[i].name);
		printf("roll_no -> %d\n",ret[i].roll_no);
		printf("sec => %c\n",ret[i].sec);
	}
		

}
