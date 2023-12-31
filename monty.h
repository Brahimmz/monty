#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
extern stack_t* head;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*op_func)(stack_t **, unsigned int);

/*readfile.c*/
void read_fl(FILE* file);

/*tokenizer.c*/
int tokeniz(char* line, int type, int count);

/*funcsch.c*/
int func_sch(char* opcode, char* value, int count, int type);
void magic(op_func funky, char* opcode, char* value, int type, int line_n);

/*lsfunc.c*/
stack_t* create_new_node(int value, int sign);
void free_nd(void);
void add_queue(stack_t** hamood, __attribute__((unused))unsigned  int line_n);

/*funcone.c*/
void push(stack_t **new_node, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/*functwo.c*/
void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);
void mult(stack_t **stack, unsigned int line_number);

/*functr.c*/
void modur(stack_t **stack, unsigned int line_number);
void dchar(stack_t **stack, unsigned int line_number);
void dstr(stack_t **stack, unsigned int line_number);
void rot0(stack_t **stack, unsigned int line_number);
void rotd(stack_t **stack, unsigned int line_number);

#endif /*MONTY_H*/
