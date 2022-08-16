#include "monty.h"

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

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
