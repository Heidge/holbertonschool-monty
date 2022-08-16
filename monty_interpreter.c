#include "monty.h"

void monty_interpreter(FILE *fp)
{
	char *line == NULL; /** stocke le fichier */
	size_t len = 0; /** taille du fichier */
	char *token1 = NULL; /** nom du fichier */
	char *token2 = NULL; /** NULL */
	stack_t *stack == NULL;
	int counter = 0;

	while (getline(&line, &len, fp) != -1)
	{
		counter++;
		token1 = strtok(line, " \n");
		token2 = strtok(NULL, " \n");
		if (token1 != NULL)
		opcode(token1, &stack, counter);
	}
	free(line);
}
