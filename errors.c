#include "monty.h"
/**
 * errors - Function that print the error ID
 * @id: id of the error
 * @file: name of the file
 * @counter: line number
 * Return: nothing
 */
void errors(int id, char *file, int counter)
{
	switch (id)
	{
	case 1:
		fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
		exit(EXIT_FAILURE);
		break;
	case 2:
		(void)file;
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		break;
	case 3:
		(void)file;
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		exit(EXIT_FAILURE);
		break;
	case 4:
		(void)file;
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		exit(EXIT_FAILURE);
	}
}
