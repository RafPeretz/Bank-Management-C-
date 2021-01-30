#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../include/customer.h"

int struct2file(Customer*);
char* get_name_file(int);
void print_file(int user_id);
Customer* file2strcut(int user_id);

