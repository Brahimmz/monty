#include "monty.h"
/**
 * pall - prints all from top
 * @stack: list head
 * @line_number: line num
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (!stack || !*stack)
		exit(EXIT_FAILURE);
	if (!ptr)
		return;
	while(ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
/**
 * pop
 * @stack: the list head
 * @line_number: the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer;
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	pointer = *stack;
	*stack = pointer->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(pointer);
}
/**
 * push - adds new elmts to stack
 * @new_node: list head
 * @line_number: line num
 */
void push(stack_t **new_node, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}
/**
 * pint - print int
 * @stack: list head
 * @line_number: line num
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", ptr->n);
}
/**
 * nop - does nothing
 * @stack: list head
 * @line_number: line num
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
