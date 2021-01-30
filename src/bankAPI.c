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
    printf("2. View customer's list\n");
    printf("3. Update information of existing account\n");
    printf("4. For transcactions \n");
    printf("5. Removing existing account \n");
    printf("6. For transcactions\n");
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
	user_id = read_int();
	print_file(user_id);
}

void edit()
{
    int user_id;
	printf("Please enter the account's id: ");
	user_id = read_int();

    Customer *customer = file2struct(user_id);
    print_file(user_id);

    printf("Adress : ");
    read_line(customer->adress,20);

    struct2file(customer);
    free(customer);
}

 void transcat()
 {
    int user_id;
	printf("Please enter the account's id: ");
	user_id = read_int();

    int user_id_destination;
	printf("Please enter the DESTINATION account's id: ");
	read_int(&user_id_destination);
	int money2transact;
	printf("Please enter the money to transact: ");
	read_int(&money2transact);
	transact_money(user_id,user_id_destination,money2transact);



 }

 void erase()
 {
    printf("erase");
 }

void  see()
 {
    printf("see");
 }
