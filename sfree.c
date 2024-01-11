#include "monty.h"

/**
 * sfree - frees stack
 */
void sfree(void)
{
	stack_t *temp;

	if (stack != NULL)
	{
		temp = stack;
		while (stack != NULL)
			stack = (*stack).next, free(temp), temp = stack;
	}
}
