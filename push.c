#include "monty.h"

/**
 * push - Pushes an element onto the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_nber: The line nber where the instruction appears.
 */

void push(stack_t **stack, unsigned int line_nber)
{
	int n, i = 0;
	stack_t *new_node;

	if (str != NULL)
	{
		while (str[i])
		{
			if (str[0] == '-')
			{
				i++;
				continue;
			}
			if (isdigit(str[i]) == 0)
			{
				free(opcode), free(str), free(line), fclose(stream), sfree();
				fprintf(stderr, "L%d: usage: push integer\n", line_nber);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		n = atoi(str);
	}
	else
	{
		free(opcode), free(str), free(line), fclose(stream), sfree();
		fprintf(stderr, "L%d: usage: push integer\n", line_nber);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		free(opcode), free(str), free(line), fclose(stream), sfree();
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n, new_node->prev = NULL, new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
