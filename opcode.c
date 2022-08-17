#include "monty.h"

void opcode(char *token1, stack_t **stack, int counter)
{
	unsigned int i = 0;

	instruction_t list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	while (list[i].opcode != NULL) /** boucle pour parcourir tout le tableau */
	{
		if (strcmp(token1, list[i].opcode) == 0) /** match entre le token 1 de l'interpreter et le bon char de la structure */
			list[i].f(stack, counter); /** donne la bonne fonction avec arguments - stack = NULL ? */
		i++; /** continue de parcourir la boucle si pas de match */
	}
}
