#include "monty.h"

/**
 * add_to_queue - adds a node to the queue
 * @new: pointer to new node
 * @line_n: number of line
 */
void add_to_queue(stack_t **new, __attribute__((unused))unsigned int line_n)
{
	stack_t *temp;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new;
		return;
	}

	temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new;
	(*new)->prev = temp;
}

/**
 * push - pushes a node to the stack
 * @new: pointer to new node
 * @line_n: number of line
 */
void push(stack_t **new, __attribute__((unused))unsigned int line_n)
{
	stack_t *temp;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new;
	}
	temp = head;
	head = *new;
	head->next = temp;
	temp->prev = head;
}

/**
 * print_all - prints all nodes
 * @top: poiner to top of stack
 * @line_n: number of line
 */
void print_all(stack_t **top, __attribute__((unused))unsigned int line_n)
{
	stack_t *temp;

	if (!top)
		exit(EXIT_FAILURE);
	temp = *top;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop - pops a node from the stack
 * @top: pointer to top of stack
 * @line_n: number of line
 */
void pop(stack_t **top, unsigned int line_n)
{
	stack_t *temp;

	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_n);
		exit(EXIT_FAILURE);
	}
	temp = *top;
	*top = temp->next;
	if (*top != NULL)
		(*top)->prev = NULL;
	free(temp);
}

/**
 * print_top - prints the top of stack
 * @top: pointer to top of stack
 * @line_n: number of line
 */
void print_top(stack_t **top, unsigned int line_n)
{
	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}
