#include "monty.h"
/**
 * func_sch - searchs for function by name
 * launchs opcode's function
 * @opcode: actual opcode
 * @value: value that will be passed to the function push
 * to be stored in the list
 * @count: line count
 * @type: stack 0 or queue 1
 * Return: 1 if it works 0 if something wrong happens
 */
int func_sch(char *opcode, char *value, int count, int type)
{
	int i;
	instruction_t function_list[] =
	{
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divi},
		{"mul", mult},
		{"mod", modur},
		{"pchar", dchar},
		{"pstr", dstr},
		{"rotl", rot0},
		{"rotr", rotd},
		{NULL, NULL},
	};
	if (strcmp(opcode, "#") == 0)
	{
		free_nd();
		return (0);
	}

	for (i = 0; function_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, function_list[i].opcode) == 0)
		{
			magic(function_list[i].f, opcode, value, type, count);
			return (1);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", count, opcode);
	exit(EXIT_FAILURE);
}
/**
 * magic - Works magic and make stuff happen
 * @funk: function name
 * @opcode: opcode that we'll use the recheck
 * @value: value that will be passed to stack_t->n
 * @type: 1 stack 0 queue for pushing purposes
 * @line_n: line num
 */
void magic(op_func funky, char *opcode, char *value, int type, int line_n)
{
	int sign = 1, i;
	stack_t* hamood;
	if (strcmp(opcode, "push") == 0)
	{
		if (value && value[0] == '-')
		{
			sign = -1;
			value = value + 1;
		}
		if (!value)
		{
			fprintf(stderr, "L%d: usage: push integer", line_n);
			exit(EXIT_FAILURE);
		}
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer", line_n);
				exit(EXIT_FAILURE);
			}
		}
		hamood = create_new_node(atoi(value), sign);
		if (type == 1)/*queue*/
			add_queue(&hamood, line_n);
		if (type == 0)/*stack*/
			funky(&hamood, line_n);
	}
	else
	{
		funky(&head, line_n);
	}
}
