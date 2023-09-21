#include "monty.h"

/**
 * swap - swaps two elements at the top of the stack
 * @top: pointer to top of stack
 * @line_n: number of line
 */
void swap(stack_t **top, unsigned int line_n)
{
	stack_t *temp;

	if (!top || !*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	temp = (*top)->next;
	(*top)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *top;
	temp->next = *top;
	(*top)->prev = temp;
	temp->prev = NULL;
	*top = temp;
}

/**
 * add - adds two elements at the top of the stack
 * @top: pointer to top of stack
 * @line_n: number of line
 */
void add(stack_t **top, unsigned int line_n)
{
	int sum = 0;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	(*top) = (*top)->next;
	sum = (*top)->n + (*top)->prev->n;
	(*top)->n = sum;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * nop - Does nothing
 * @top: pointer to top of stack
 * @line_n: number of line
 */
void nop(stack_t **top, unsigned int line_n)
{
	(void)top;
	(void)line_n;
}

/**
 * sub - subs the two elements at the top of the stack
 * @top: pointer to top of stack
 * @line_n: number of line
 */
void sub(stack_t **top, unsigned int line_n)
{
	int res;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	(*top) = (*top)->next;
	res = (*top)->n - (*top)->prev->n;
	(*top)->n = res;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * div - divides the two elements at the top of stack
 * @top: pointer to top of stack
 * @line_n: number of line
 */
void divide(stack_t **top, unsigned int line_n)
{
	int res;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_n);
		exit(EXIT_FAILURE);
	}
	(*top) = (*top)->next;
	res = (*top)->n / (*top)->prev->n;
	(*top)->n = res;
	free((*top)->prev);
	(*top)->prev = NULL;
}
