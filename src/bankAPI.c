#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../include/ioUtils.h"
#include "../include/bankAPI.h"
#include "../include/customer.h"
#include "../include/file_action.h"


void menu()
{
    printf("WELCOME TO THE MAIN MENU \n");
    printf("1. Create new account \n");
    printf("2. Update information of existing account\n");
    printf("3. For transcactions\n");
    printf("4. Check the datails of existing account \n");
    printf("5. Removing existing account \n");
    printf("6. View customer's list \n");
    printf("7. Exit \n");
}


void new_acc()
{
    Customer *customer= print_and_scan_new_acc_messages();
    struct2file(customer);
}


void view_list()
{
    int user_id;
	printf("Please enter the account's id: ");
	user_id=read_int();
	print_file(user_id);
}

void edit()
{
    printf("edit");
}

 void transcat()
 {
     printf("transcat");
 }

 void erase()
 {
     printf("erase");
 }

void  see()
 {
     printf("see");
 }
