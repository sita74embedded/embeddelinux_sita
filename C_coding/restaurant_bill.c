#include<stdio.h>
#include<stdlib.h>

struct items
{
	char name_item[50];
	float price;
	float quantity;
	char name_customer[50];
	long int mobile_number;
	float bill;
};

int main()
{
	struct items var,*ptr;
	var.bill=0;
	printf("Enter the customer name\n");
	scanf("%[^\n]s",var.name_customer);
	printf("Enter the mobile number\n");
	scanf("%ld",&var.mobile_number);
	int n;
	printf("Enter the number of items\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	printf("Enter the item\n");
	scanf(" %[^\n]s",var.name_item);
	printf("Enter the quantity\n");
	scanf("%f",&var.quantity);
	printf("Enter the price\n");
	scanf("%f",&var.price);
        var.bill=(var.quantity)*(var.price)+var.bill;
	}
	printf("name of the customer is %s\n",var.name_customer);
	printf("customer mobile number %ld\n",var.mobile_number);
	printf("%f",var.bill);	
}



