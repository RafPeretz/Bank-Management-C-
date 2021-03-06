#include "../include/file_action.h"
#include "../include/ioUtils.h"
#define ID_LEN 	20


int struct2file(Customer *person)
{
	const char* write_format = "%s\n%s\n%d\n%d";

	char *path = get_name_file(person->id);
	FILE *costumer_file = fopen(path, "w+");

	if (costumer_file != NULL)
	{
		fprintf(costumer_file, write_format, person->name, person->adress, person->money, person->id);
		fclose(costumer_file);
		printf("Have a great day sir!\n \n \n");
		free(path);
		free(person);
		return 1;
	}
	else
	{
		printf("Error: cannot open file %d.txt!\n", person->id);
		free(path);
		free(person);
		return 0;
	}
	
}



char* get_name_file(int user_id) //rend le nom d'un file 
 {
	 
	char *path = (char*)malloc(100 * sizeof(char));
	strcpy(path, "");
	char file_name[ID_LEN] = "";

	snprintf(file_name, ID_LEN, "%d", user_id); //fait la meme chose que itoa

	strcat(file_name, ".txt"); //addition deux string
	strcat(path, file_name);


	return path;
}

Customer* file2struct(int user_id)
{
	Customer *client =(Customer*)malloc(sizeof(Customer));
	char *file_name = get_name_file(user_id);
	FILE* fptr; 

	fptr = fopen(file_name, "r"); 

	if(file_name == NULL)
	{
		printf("Error \n");
		exit(0);
	}
	
	char buffer[100] = "";
	int line_num = 0;
	while (read_line_file(buffer, sizeof(buffer), fptr) != NULL)
	{
		switch (line_num)
		{
		case 0:
			strcpy(client->name,buffer);
			break;
		
		case 1:
			strcpy(client->adress,buffer);
			break;

		case 2:
			client->id = snprintf(file_name, ID_LEN, "%d", user_id);
			break;
		
		case 3:
			client->money = snprintf(file_name, ID_LEN, "%d", user_id);
			break;
		}
		line_num++;
		strcpy(buffer,"");

	}

	free(file_name);
	return client;
	


}

void print_file(int user_id)
{
	const char* show_file_format = "Name: %s\n ID: %d\n Adress: %s\n Money: %d\n\n\n";
	char* name_file = get_name_file(user_id);
	Customer* clients = NULL;
	FILE* fptr; 
	
	fptr = fopen(name_file, "r"); 
    if (fptr != NULL) 
    { 
        clients = file2struct(user_id);
		printf(show_file_format,clients->name,clients->id,clients->adress,clients->money);
    } 
	
	else 
			printf("You entered wrong id \n");
    		free(clients);
}

void transact_money(int id_source,int id_destination,int money)
{
	Customer *customer_source = file2struct(id_source);
	Customer *customer_destination = file2struct(id_source);

	customer_source->money -= money;
	customer_destination->money += money;

	struct2file(customer_source);
	struct2file(customer_destination);
}


void remove_file(int user_id)
{
	char* name_file = get_name_file(user_id);

	if (remove(name_file) == 0) 
      printf("Deleted successfully"); 
   else
      printf("Unable to delete the file"); 

}



