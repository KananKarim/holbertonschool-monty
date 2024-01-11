#include "monty.h"

/**
 * parser - parses line and segments it to command and param
 * @line: line from .m file
 * @ln: number of current line
 */

void parser(char **line, unsigned int ln)
{
	char *command; /* exctracted command from line */

	command = strtok(*line, " \n\t");
	if (command == NULL)
		return;

	if (opcode != NULL)
		free(opcode);

	opcode = strdup((const char *)command);
	if (opcode == NULL)
	{
		free(opcode), free(str), free(line), fclose(stream), sfree(),
		fprintf(stderr, "Error: malloc failed\n"),
		exit(EXIT_FAILURE);
	}

	str = strtok(NULL, " \n\t");

	interpreter(opcode, str, ln);
}
