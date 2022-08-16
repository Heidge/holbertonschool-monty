#include "monty.h"

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void empiler(stack_t **stack, unsigned line_number)
{
	stack_t *p_nouveau = malloc(sizeof(*p_nouveau));

    p_nouveau->n = n;
    p_nouveau->prev = *p_pile;
	*p_pile = p_nouveau;
}
