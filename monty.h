#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

int read_line(char *content, int line_n, int format);
void execute(char *opcode, char *data, int line_n, int format);
void execute_func(op_func func, char *opcode, char *data,
                        int line_n, int format);
stack_t *make_node(int n);
void free_nodes(void);
void add_to_queue(stack_t **new, unsigned int line_n);
void push(stack_t **new, unsigned int line_n);
void print_all(stack_t **top, unsigned int line_n);
void pop(stack_t **top, unsigned int line_n);
void push(stack_t **top, unsigned int line_n);
void add(stack_t **top, unsigned int line_n);
void nop(stack_t **top, unsigned int line_n);
void print_top(stack_t **top, unsigned int line_n);
void swap(stack_t **top, unsigned int line_n);
void divide(stack_t **top, unsigned int line_n);
void mul(stack_t **top, unsigned int line_n);
void mod(stack_t **top, unsigned int line_n);
void print_char(stack_t **top, unsigned int line_n);
void print_str(stack_t **top, unsigned int line_n);
void rotl(stack_t **top, unsigned int line_n);
void rotr(stack_t **top, unsigned int line_n);
void sub(stack_t **top, unsigned int line_n);
#endif
