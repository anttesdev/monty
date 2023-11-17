#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty script
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->prev->next = NULL;
		temp->prev = NULL;
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = temp;
	}
}

