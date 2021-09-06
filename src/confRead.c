#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "confRead.h"


int
printFileContent(const char* file_name)
{
	char line[256];
	FILE *config;

        config = fopen(file_name, "r");
        if(config != NULL)
	{
                while(fgets(line, sizeof(line), config) != NULL)
		{
                        printf("%s(): %s\n", __func__, line);
                }
        }
        else
	{
                printf("%s(): Config file does not open. \n", __func__);

                return -1;
        }

        fclose(config);

	return 0;
}

static int
takeVariableFromLine(char *str, char *name, char *data)
{
	char* line = strtok(str, "=");

	strcpy(name, line);
	line = strtok(NULL, "\n");
	strcpy(data, line);;
	return 0;
}


int
takeFileContent(const char* file_name, struct data_holder** data_in_file_ptr, int* data_holder_size)
{
	char line[256];
	FILE *config;
	
	char name[128];
	char data[128];

	int data_index = 0;

        config = fopen(file_name, "r");
        if(config != NULL)
	{
                while(fgets(line, sizeof(line), config) != NULL)
		{
			
			*data_in_file_ptr = realloc(*data_in_file_ptr, (data_index+1) * sizeof(struct data_holder));	
			takeVariableFromLine(line,name,data);
			
			struct data_holder* temp_ptr = *data_in_file_ptr + data_index;

			strcpy(temp_ptr->name,name);
			strcpy(temp_ptr->data,data);
			
			data_index++;	
			printf("%d\n", data_index);
		}

		*data_holder_size = data_index;
        }
        
	else
	{
                printf("%s(): Config file does not open. \n", __func__);
                return -1;
        }

        fclose(config);

	return 0;
}

int
dataAsInt(const char* data_name, const struct data_holder* data_in_file_ptr, int data_holder_size) {
	
	for(int i = 0; i < data_holder_size; ++i) {
		if (!strcmp(data_in_file_ptr[i].name, data_name)) {
			return atoi(data_in_file_ptr[i].data);
		}	
	}
	return -1;
}

char*
dataAsStr(const char* data_name, const struct data_holder* data_in_file_ptr, int data_holder_size) {
	
	for(int i = 0; i < data_holder_size; ++i) {
		if (!strcmp(data_in_file_ptr[i].name, data_name)) {
			return (char*)data_in_file_ptr[i].data;
		}	
	}
	return NULL;
}

float
dataAsFloat(const char* data_name, const struct data_holder* data_in_file_ptr, int data_holder_size) {

        for(int i = 0; i < data_holder_size; ++i) {
                if (!strcmp(data_in_file_ptr[i].name, data_name)){
	        	return atof(data_in_file_ptr[i].data);
		}
	}
	return -1.0;
}
