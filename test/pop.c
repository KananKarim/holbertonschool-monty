#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The line number where the instruction appears.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
	{
		free(opcode), free(str), free(line), fclose(stream);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (*stack)
		(*stack)->prev = NULL;
}
