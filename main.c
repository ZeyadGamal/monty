#include "monty.h"

/**
 * main - main entry to the program
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *file;
	int line_n, format = 0;
	char *content = NULL;
	size_t len = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (line_n = 1; getline(&content, &len, file) != -1; line_n++)
		format = read_line(content, line_n, format);
	free(content);
	fclose(file);

	return (0);
}
