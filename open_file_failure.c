#include "monty.h"

void open_file_failure(void)
{
	int file_input;

	scanf("%d", &file_input);
	fprintf(stderr, "Error: Can't open file %d\n", file_input);
	exit(EXIT_FAILURE);
}
