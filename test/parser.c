#include "monty.h"

/**
 * parser - parses line and segments it to command and param
 * @line: line from .m file
 * @ln: number of current line
 *
 * Return: 0 on succes, -1 on error
 */

int parser(char **line, unsigned int ln)
{
	char *command, *opcode, *str; /* exctracted opcode from line */
	int n = 0;
	(void)ln;

	command = strtok(*line, " \n\t");

	if (command == NULL)
		return (0);

	str = strtok(NULL, " \n\t");
	if (str != NULL && isdigit(str[0]) != 0)
                n = atoi(str);

	opcode = strdup((const char *)command);
	if (opcode == NULL)
		return (-1);

	printf("line is %s, opcode is %s, command is %s, n is %d\n", *line, opcode, command, n);
	free(opcode);
	return (0);
}
