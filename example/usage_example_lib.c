#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <confRead.h>

int
main(int argc, char **argv)
{
	int debug;
	char* IP;
	char* password;
    struct data_holder* data_in_file_ptr = NULL;
	int data_holder_size = 0;

	takeFileContent(argv[1], &data_in_file_ptr, &data_holder_size);

	debug = dataAsInt("debug", data_in_file_ptr, data_holder_size);
	IP = dataAsStr("IP", data_in_file_ptr, data_holder_size);
	password = dataAsStr("Password", data_in_file_ptr, data_holder_size);

	printf("Debug: [%d], Password: [%s], IP:[%s]\n", debug, password, IP);

	free(data_in_file_ptr);

	return 0;
}
