#include "monty.h"

/**
 * match - Matches the opcode and calls the corresponding function
 * @opcode: The opcode to match
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty script
 */

void match(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

