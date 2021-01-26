#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../include/ioUtils.h"
#include "../include/bankAPI.h"
#include "../include/customer.h"


struct2file()
{
       FILE *outfile; 
      
    // open file for writing 
    outfile = fopen ("testfile.txt", "w"); 
    if (outfile == NULL) 
    {
        fprintf(stderr, "\nError opend file\n"); 
        exit (1); 
    }

    Customer *customer = (Customer*)malloc(sizeof(Customer));

    printf("Please enter your name \n");
    char name_customer[50];
    read_line(name_customer,50);
    strcpy(customer->name,name_customer);


    printf("Please enter your id \n");
    int id=read_int();
    customer->id=id;

    printf("Please enter your money \n");
    int money=read_int();
    customer->money=money;

    printf("Please enter your adress \n");
    char adress_customer[50];
    read_line(adress_customer,50);
    strcpy(customer->adress,adress_customer);

    printf("Contents of structure %s "" %d " " %d " " %s \n",customer->name,customer->id,customer->money,customer->adress);




    fwrite(&customer, sizeof(Customer), 1, outfile);

    if(fwrite != 0)  
        printf("contents to file written successfully !\n"); 
    else 
        printf("error writing file !\n"); 
  
    // close file 
    fclose (outfile); 
   

    printf("Contents of structure %s %d %d %s",customer->name,customer->id,customer->money,customer->adress);



}