#include "monty.h"
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

char *token2 = NULL; /** NULL */

void monty_interpreter(FILE *fp)
{
	char line[100]; /** stocke le fichier */
	char *token1 = NULL; /** nom du fichier */
	stack_t *stack = NULL;
	int counter = 0;

	while (fgets(line, 100, fp))
	{
		counter++;
		token1 = strtok(line, " \n");
		token2 = strtok(NULL, " \n");
		if (token1 != NULL)
		opcode(token1, &stack, counter);
	}
	free_stack(stack);
}
