#include "monty.h"

/**
 * mult - Multiplies the second top element of the stack by the top element
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty script
 */

void mult(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * modu - Computes the rest of the division of the second top element
 * of the stack by the top element
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty script
 */

void modu(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * pchar - Print the character at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty script.
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int char_value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	char_value = (*stack)->n;
	if (char_value < 0 || 127 < char_value)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)char_value);
}

