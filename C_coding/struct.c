#include<stdio.h>
#include<stdlib.h>
struct restaurant
{
	char customer_name[100];
	long int mobilenumber;
	char item_name[100];
	float quantity;
	float price;
	float total_amount;
};
int main()
{
	struct restaurant var,*ptr;
	int n,i;
	float total_bill=0;
	printf("Enter the number of items\n");
	scanf("%d",&n);
	ptr=(struct restaurant*)malloc(n*sizeof(struct restaurant));
	ptr->total_amount=0;
	for(i=0;i<n;i++)
	{
		getchar();
		printf("Enter the item name::\n");
		scanf("%[^\n]s",ptr[i].item_name);
		printf("Enter the quantity::\n");
		scanf("%f",&ptr[i].quantity);
		printf("\n");
		printf("Enter the price::\n");
		scanf("%f",&ptr[i].price);
		printf("\n");
		ptr[i].total_amount = ptr[i].quantity * ptr[i].price;
		total_bill=ptr[i].total_amount+total_bill;
	}
	printf("the total bill is :::%f\n",total_bill);
	free(ptr);

}
