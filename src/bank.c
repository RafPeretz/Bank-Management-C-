#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../include/ioUtils.h"
#include "../include/bankAPI.h"
#include "../include/file_action.h"

void exec_option(int option);



int main ()
{
    menu();
    int option = read_int();
    exec_option(option);
    return 0;
}




void exec_option(int option)
{
    switch (option)
    {
    case 1:
        new_acc();
        break;

    case 2:

        view_list();
        break;

    case 3: 
        edit();
        break;
    
    case 4:
        transcat();
        break;
    
    case 5: 
        erase();
        break;

    case 6:
        see();
        break;

    
    default:
        printf("error\n");
        // error msg
        break;
    } 
}


