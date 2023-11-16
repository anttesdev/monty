#include "monty.h"

/**
 * process - a function to process a monty script line by line
 * @file: the monty script to be processed
 * @stack: Double pointer to the top of the stack
 * Return: EXIT_SUCCESS on success and EXIT_FAILURE on failure
 */

int process(FILE *file, stack_t **stack)
{
	char *lineptr = NULL;
	size_t n = 0;
	unsigned int line_number = 0;
	ssize_t line;

	while ((line = getline(&lineptr, &n, file)) != -1)
	{
		line_number++;
		tokens = tokenize(lineptr);
		if (line > 0 && lineptr[line - 1] == '\n')
			lineptr[line - 1] = '\0';
		if (tokens[0] != NULL)
		{
			match(tokens[0], stack, line_number);
		}
		free_tokens(tokens);
	}
	free(lineptr);
	if (feof(file))
	{
		return (EXIT_SUCCESS);
	}
	else
	{
		return (EXIT_FAILURE);
	}
}






