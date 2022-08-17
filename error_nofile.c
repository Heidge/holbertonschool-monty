#include "monty.h"
/**
 * usage_error - print error no file if user don't write 2 arguments
 *
 */
void usage_error(void)
{
	printf("USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
