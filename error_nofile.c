#include "monty.h"

void usage_error_nofile(void)
{
	fprintf(stderr, "USAGE: monty file\n")
	exit(EXIT_FAILURE);
}
