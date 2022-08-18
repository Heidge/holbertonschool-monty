#include "monty.h"


/**
 * push - entry point
 * @stack: stack_t variable
 * @number: int variable
*/

void push(stack_t **stack, unsigned int number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freestack(stack);
		exit(EXIT_FAILURE);
	}

	new->n = number;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;
	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void pint(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * nop - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void nop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}

/**
 * swap - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL || (tmp->next == NULL && tmp->prev == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp->prev = tmp->next;
	tmp->next->prev = NULL;
	tmp->next = tmp->next->next;
	tmp->prev->next = tmp;
	(*stack) = tmp->prev;
}
/**
 * pop - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if ((tmp) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (tmp->next == NULL)
	{
		(*stack) = NULL;
		free(tmp);
	}
	else
	{
		tmp = tmp->next;
		tmp->prev = NULL;
	}
}

/**
 * add - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void add(stack_t **stack, unsigned int line_number)
{
	unsigned int sum;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, sum);
}

/**
 * sub - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void sub(stack_t **stack, unsigned int line_number)
{
	unsigned int res;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	res = (*stack)->next->n - (*stack)->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, res);
}

/**
 * division - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void division(stack_t **stack, unsigned int line_number)
{
	unsigned int divide;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	divide = (*stack)->next->n / (*stack)->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, divide);
}

/**
 * mul - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void mul(stack_t **stack, unsigned int line_number)
{
	unsigned int power;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	power = (*stack)->next->n * (*stack)->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, power);
}

/**
 * mod - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void mod(stack_t **stack, unsigned int line_number)
{
	unsigned int module;
	(void)line_number;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	module = (*stack)->next->n % (*stack)->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, module);
}

/**
 * pchar - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void pchar(stack_t **stack, unsigned int line_number)
{
	int letter;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	letter = (*stack)->n;

	if (letter >= 0 && letter <= 255)
	{
		putchar(letter);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range,\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	int string;
	stack_t *tmp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	while (tmp)
	{
		string = tmp->n;
		if (string > 0 && string <= 127)
			putchar(string);
		else
			break;
		tmp = tmp->next;
	}
	putchar('\n');
}
/**
 * freestack - enrty point
 * @stack: stack_t variable
*/

void freestack(stack_t **stack)
{
	stack_t *tmp;

	while ((*stack) != NULL)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		free(tmp);
	}
}

/**
 * _isdigit - function that checks for a digit (0 through 9)..
 * @c: digit
 * Return:Returns 1 when c is a digit and 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}



