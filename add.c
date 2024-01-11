#include "monty.h"

/**
 * add - Swaps the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The line number where the instruction appears.
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		free(opcode), free(str), free(line), fclose(stream), sfree();
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n += temp->n;
	free(temp);
}
