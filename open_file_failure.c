#include "monty.h"

void open_file_failure()
{
	int file_input;

	scanf("%d\n", &file_input);
	fprintf(stderr, "Error: Can't open file %d\n", file_input);
	exit(EXIT_FAILURE);
}
