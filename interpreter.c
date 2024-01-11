#include "monty.h"

/**
 * interpreter - interprets parsed command to stack functions
 * @opcode: command to execute
 * @str: str
 * @ln: line number
 */
void interpreter(char *opcode, char *str, unsigned int ln)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop}
	};
	unsigned int i = 0, count = sizeof(ops) / sizeof(instruction_t);

	(void) str;
	while (i < count)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(&stack, ln);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", ln, opcode);
	free(opcode);
	if (line != NULL)
		free(line);
	fclose(stream);
	sfree();
	exit(EXIT_FAILURE);
}
