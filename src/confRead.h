#ifndef CONFIGURATION_READER_H
#define CONFIGURATION_READER_H

#ifdef __cplusplus
extern "C"
{
#endif


/**
 * struct data_holder - indicates variable names and values
 *
 * @name: variable name
 * @data: variable value
 */
struct data_holder
{
	char name[512];
	char data[512];
};


/**
 * printFileContent - prints the content of the given file.
 * @file_name: path 
 */
int printFileContent(const char* file_name);

/**
 * takeFileContent - takes variable from file and makes available other functions
 */
int takeFileContent(const char* file_name, struct data_holder** data_in_file_ptr, int* data_holder_size);

/**
 * dataAsInt - converts given data type to integer
 */
int dataAsInt(const char* data_name, const struct data_holder* data_in_file_ptr, int data_holder_size);

/**
 * dataAsStr - converts given data type to string
 */
char* dataAsStr(const char* data_name, const struct data_holder* data_in_file_ptr, int data_holder_size);

/**
 * dataAsFloat - converts given data type to float
 */
float dataAsFloat(const char* data_name, const struct data_holder* data_in_file_ptr, int data_holder_size);

#ifdef __cplusplus
}
#endif

#endif
