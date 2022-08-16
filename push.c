#include "monty.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

void empiler(stack_t **p_pile, int n)
{
	stack_t *p_nouveau = malloc(sizeof(*p_nouveau));

    p_nouveau->n = n;
    p_nouveau->prev = *p_pile;
	*p_pile = p_nouveau;
}
