#include "monty.h"

/**
 * rotr - rotates the last node of the stack to the top.
 * @top: pointer to top stack
 * @line_n : number of line
 */
void rotr(stack_t **top, __attribute__((unused))unsigned int line_n)
{
	stack_t *temp;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		return;

	temp = *top;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *top;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*top)->prev = temp;
	(*top) = temp;
}
