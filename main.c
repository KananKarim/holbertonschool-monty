#include "monty.h"

/**
 * main - entry point to monty interpreter
 * @argc: counter of args
 * @argv: array of args
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int r = 0; /* return value of getline() */
	size_t bufsz = 0; /* buffer size */
	unsigned int ln = 1; /* line number */

	opcode = NULL, str = NULL, line = NULL, stream = NULL, stack = NULL;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	stream = fopen(argv[1], "r");
	if (stream == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);

	while (true)
	{
		r = getline(&line, &bufsz, stream);
		if (r == -1)
			break;
		parser(&line, ln);
		ln++;
	}
	free(opcode), fclose(stream), sfree();
	if (line != NULL)
		free(line);
	return (0);
}
