#include "monty.h"
/**
 * create_new_node - create a new node that isn't linked to anything
 * @value: data value that will be associated with new node
 * @sign:  sign of new value being treated on its own
 * Return: ptr to new node
*/
stack_t *create_new_node(int value, int sign)
{
    stack_t *new;

    new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new->n = value * sign;
    new->next = NULL;
    new->prev = NULL;
    return(new);
}
/*
 * free_nd - frees entire thing when we are done
*/
void free_nd(void)
{
	stack_t *ptr;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
}
/**
 * add_queue - because it's a queue we have to fueue
 * @hamood: node to be added
 * @line_n: line count
*/
void add_queue(stack_t **hamood, __attribute__((unused))unsigned  int line_n)
{
    stack_t *ptr = *hamood;

    if (!hamood || !*hamood)
        exit(EXIT_FAILURE); 
    if (!head)
        head = *hamood;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    (*hamood)->next = NULL;
    (*hamood)->prev = ptr;
    ptr->next = *hamood;
}
