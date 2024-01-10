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
	FILE *stream = NULL; /* file to open */
	char *line = NULL; /* line to parse and then execute */
	int r = 0; /* return value of getline() */
	size_t bufsz = 0; /* buffer size */
	unsigned int ln = 1; /* line number */

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	stream = fopen(argv[1], "r");
	if (stream == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);

	while (true)
	{
		r = getline(&line, &bufsz, stream);
		if (r == -1)
			break; /* error checking */
		if (parser(&line, ln) == -1)
			free(line),
				fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
		ln++;
	}
	free(line);
	fclose(stream);
	return (0);
}
