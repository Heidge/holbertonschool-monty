#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *s_new;

	if (token2 == NULL)
	{
		free_stack(*stack);
		errors(3, "namefile", line_number);
	}

	s_new = malloc(sizeof(stack_t));

	if (s_new == NULL)
	{
		free_stack(*stack);
		errors(2, "test", line_number);
	}

	s_new->n = atoi(token2);
	s_new->prev = NULL;

	if(*stack == NULL)
	{
		s_new->next = NULL;
		*stack = s_new;
	}
	else
	{
		s_new->next = *stack;
		(*stack)->prev = s_new;
		*stack = s_new;
	}
}

void pall(stack_t **stack, unsigned int line_number)
{

	stack_t *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

void pint(stack_t **stack, unsigned int line_number)
{
	if(*stack == NULL)
	errors(1, "1", line_number);

	printf("%d\n", (*stack)->n);

}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		errors(4, "namefile", line_number);
	}
	tmp = (*stack);
	if (tmp->next == NULL)
	{
		free(tmp);
		*stack = NULL;
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}

}

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


void free_stack(stack_t *top)
{
	stack_t *tmp;

	while (top != NULL)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
}
