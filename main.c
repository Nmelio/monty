#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - main code to monty interpreter
*
* @argc: arguments
* @argv: locator
*
* Return: 0
*/

int main(int argc, char *argv[])
{
	char *c;
	FILE *file;
	size_t size = 0;
	ssize_t r = 1;
	stack_t *s = NULL;
	unsigned int w = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (r > 0)
	{
		c = NULL;
		r = getline(&c, &size, file);
		bus.c = c;
		w++;
		if (r > 0)
		{
			A7(c, &s, w, file);
		}
		free(c);
	}
	A8(s);
	fclose(file);
return (0);
}
