
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/customer.h"

int read_int()
{
    int num = -1;
    scanf("%d", &num);
    getchar();
    return num;
}


char *read_line(char *str, int n)
{
    char *ans = fgets(str, n, stdin);
    int newline_index = strlen(str)-1;
    str[newline_index] = 0;
    return ans;
}





Customer* input_customer_details()
{

	

    Customer *customer = (Customer*)malloc(sizeof(Customer));


	
	printf("Please enter your name \n");
    char name_customer[50];
    read_line(name_customer,50);
    strcpy(customer->name,name_customer);

    printf("Please enter your id \n");
    int id=read_int();
    customer->id=id;

	printf("Please enter your adress \n");
    char adress_customer[50];
    read_line(adress_customer,50);
    strcpy(customer->adress,adress_customer);

	printf("Please enter your money \n");
    int money=read_int();
    customer->money=money;

	return customer;
}