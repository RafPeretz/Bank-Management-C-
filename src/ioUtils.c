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


char* read_line(char *str, int n)
{
    char *ans = fgets(str, n, stdin);
    int newline_index = strlen(str)-1;
    str[newline_index] = 0;
    return ans;
}

char* read_line_file(char *str, int n, FILE *stream)
{
	char *ans = fgets(str, n, stream); 
	if (ans == NULL)
		return NULL;
        
	int newlineIndex = strcspn(str, "\n");
	str[newlineIndex] = 0;
	return str;
}



Customer* print_and_scan_new_acc_messages()
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

