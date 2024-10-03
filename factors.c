#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

/**
 * factorize - Find and print the factors of a number
 * @n: The number to factorize
 */
void factorize(unsigned long long n)
{
	unsigned long long i;

	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			printf("%llu=%llu*%llu\n", n, n / i, i);
			return;
		}
	}
	printf("%llu=%llu*1\n", n, n);
}

/**
 * kstrtoull - Convert a string to an unsigned long long
 * @s: The string to convert
 * @base: The base of the number in the string
 * @res: Pointer to the result variable
 *
 * Return: 0 on success, -EINVAL or -ERANGE on failure
 */
int kstrtoull(const char *s, unsigned int base, unsigned long long *res)
{
	char *endp;
	unsigned long long val;

	if (s == NULL || *s == '\0')
		return (-EINVAL);

	errno = 0;
	val = strtoull(s, &endp, base);

	if (*endp != '\0')
		return (-EINVAL);

	if (errno == ERANGE)
		return (-ERANGE);

	*res = val;
	return (0);
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
	unsigned long long n;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		if (kstrtoull(line, 10, &n) == 0)
			factorize(n);
	}

	fclose(file);
	free(line);
	return (0);
}
