#include "monty.h"
stack_t *head = NULL;
/**
 * main - main program that'll run everything
 * @argc: num of argumts needs to be 2
 * @argv: argumt holder
 * Return: Not decided yet
 */
int main(int argc, char *argv[])
{
	FILE *read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read = fopen(argv[1], "r");
	if (!read)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_fl(read);
	free_nd();
	fclose(read);
	return (0);
}
