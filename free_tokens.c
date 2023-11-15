#include "monty.h"

/**
 * free_tokens - Frees an array of tokens
 * @tokens: The array of tokens to be freed
 */
void free_tokens(char **tokens)
{
	int i;

	if (tokens != NULL)
	{
		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
	}
}
