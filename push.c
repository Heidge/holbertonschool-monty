#include "monty.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	stack_t *p_new = malloc(sizeof *p_new);

	if (p_new != NULL)
	{
		tmp = (*stack)->next;
		p_new->prev = *stack;
		p_new->next = tmp;
	}
	(void)line_number;

}
