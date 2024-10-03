#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * factorize - Find and print the smallest factor of a number
 * @n: The number to factorize
 */
void factorize(long long n)
{
	long long i;

	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			printf("%lld=%lld*%lld\n", n, n / i, i);
			return;
		}
	}
	printf("%lld=%lld*1\n", n, n);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		exit(1);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		long long n = atoll(line);

		factorize(n);
	}

	fclose(file);
	if (line)
		free(line);

	return (0);
}
