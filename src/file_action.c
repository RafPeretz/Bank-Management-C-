#include "../include/file_action.h"

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
		return 1;
	}
	else
	{
		printf("Error: cannot open file %d.txt!\n", person->id);
		return 0;
	}
	free(path);
	free(person);
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

