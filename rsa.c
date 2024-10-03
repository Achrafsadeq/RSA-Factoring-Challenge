#include "factor.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Main function that reads a file and factorizes each line
 * @argc: Argument count
 * @argv: Argument vector (array of arguments)
 *
 * Return: 0 on success, exits with error on failure
 */
int main(int argc, char *argv[])
{
	FILE *fptr;
	size_t count = 0;
	ssize_t line;
	char *buffer = NULL;

	/* Check for correct number of arguments */
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* Open the file for reading */
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Read each line from the file and factorize */
	while ((line = getline(&buffer, &count, fptr)) != -1)
	{
		factorize(buffer);
	}

	/* Free the buffer and close the file */
	free(buffer);
	fclose(fptr);

	return (0);
}

