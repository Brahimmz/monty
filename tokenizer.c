#include "monty.h"
/**
 * tokenizer - separates line word by word
 * @line: line
 * @type: initially 0 but this function'll find out for sure
 * @count: line num
 * Return: should return type of structure(stack or queue)
 */
int tokeniz(char *line, int type, int count)
{
	char *opcode, *value;

	opcode = strtok(line, "\n ");
	if (!opcode)
		return (type);
	value = strtok(NULL, "\n ");
	if (strcmp(opcode, "stack") == 0)
	{
		type = 0;
		return (type);
	}
	if (strcmp(opcode, "queue") == 0)
	{
		type = 1;
		return (type);
	}
	func_sch(opcode, value, count, type);
	return(type);
}
