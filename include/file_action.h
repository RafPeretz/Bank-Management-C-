#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../include/customer.h"

int struct2file(Customer *);
char* get_name_file(int user_id);
void print_file(int user_id);
Customer* file2struct(int user_id);
void transact_money(int id_source,int id_destination,int money);
