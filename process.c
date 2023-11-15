#include "monty.h"

/**
 * process - a function to process a monty script line by line
 * @file: the monty script to be processed
 * Return: EXIT_SUCCESS on success and EXIT_FAILURE on failure
 */

int process(FILE *file)
{
	char *lineptr = NULL;
	size_t n = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL; 


	while (getline(&lineptr, &n, file) != -1)
	{
		line_number++;
		tokens = tokenize(lineptr);
		if (tokens[0] != NULL)
		{
			match(tokens[0], &stack, line_number);
		}
		free_tokens(tokens);
	}
	free(lineptr);
	return (EXIT_SUCCESS);
}






