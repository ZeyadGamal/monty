#include "monty.h"

/**
 * mul - multiplies the top two telements at the stack
 * @top: pointer to top stack
 * @line_n: number of line
 */
void mul(stack_t **top, unsigned int line_n)
{
	int product;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	(*top) = (*top)->next;
	product = (*top)->n * (*top)->prev->n;
	(*top)->n = product;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * mod - modulus the top two elements at the stack
 * @top: pointer to top of stack
 * @line_n: number of line
 */
void mod(stack_t **top, unsigned int line_n)
{
	int quotient;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_n);
		exit(EXIT_FAILURE);
	}

	(*top) = (*top)->next;
	quotient = (*top)->n % (*top)->prev->n;
	(*top)->n = quotient;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * print_char - prints the ASCII value of a character
 * @top: pointer to top
 * @line_n: number of line
 */
void print_char(stack_t **top, unsigned int line_n)
{
	int value;

	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_n);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", value);
}

/**
 * print_str - prints a string
 * @top: pointer to top
 * @line_n: number of line
 */
void print_str(stack_t **top, unsigned int line_n)
{
	int value;
	stack_t *temp;

	(void)line_n;

	if (top == NULL || *top == NULL)
	{
		printf("\n");
		return;
	}

	temp = *top;
	while (temp)
	{
		value = temp->n;
		if (value <= 0 || value > 127)
			break;
		printf("%c", value);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the first node of the stack to the bottom
 * @top: pointer to top
 * @line_n: number of line
 */
void rotl(stack_t **top, unsigned int line_n)
{
	stack_t *temp;

	(void)line_n;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		return;
	temp = *top;
	while (temp->next)
		temp = temp->next;
	temp->next = *top;
	(*top)->prev = temp;
	*top = (*top)->next;
	(*top)->prev->next = NULL;
	(*top)->prev = NULL;
}
