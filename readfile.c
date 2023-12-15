#include "monty.h"
/**
 * read_fl - reads file and calls strtok to tokenize and stores
 * @file: file pointer
 * Return: not decided yet
 */
void read_fl(FILE *file)
{
	int counter = 0, type = 0;
	char *buffer = NULL;
	size_t len = 0;
	for (counter = 1; getline(&buffer, &len, file) != -1; counter++)
	{
		tokeniz(buffer, type, counter);
	}
	free(buffer);
}
