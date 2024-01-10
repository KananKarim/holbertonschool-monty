#include "monty.h"

/**
 * push - Pushes an element onto the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The line number where the instruction appears.
 * @n: The integer to be added to the stack.
 */

void push(stack_t **stack, unsigned int line_number, char *n)
{
	int num;
	stack_t *new_node;

	num = atoi(n);

	if (num == 0 && *n != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
