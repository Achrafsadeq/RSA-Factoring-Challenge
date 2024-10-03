#include "factor.h"
#include <inttypes.h>

/**
 * factorize_number - Attempt to factorize a number into two smaller numbers
 * @n: The number to factorize
 * @p: Pointer to store the first factor
 * @q: Pointer to store the second factor
 *
 * Return: true if factorization is successful, false otherwise
 */
bool factorize_number(uint64_t n, uint64_t *p, uint64_t *q)
{
	uint64_t i;

	if (n % 2 == 0)
	{
		*p = 2;
		*q = n / 2;
		return (true);
	}

	for (i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
		{
			*p = i;
			*q = n / i;
			return (true);
		}
	}

	return (false);
}

/**
 * factorize_file - Read numbers from a file and factorize them
 * @filename: The name of the file to read from
 */
void factorize_file(const char *filename)
{
	FILE *file = fopen(filename, "r");
	char line[MAX_LINE_LENGTH];
	uint64_t n, p, q;

	if (!file)
	{
		fprintf(stderr, "Error: Cannot open file %s\n", filename);
		exit(1);
	}

	while (fgets(line, sizeof(line), file))
	{
		n = strtoull(line, NULL, 10);
		if (n <= 1)
			continue;

		if (factorize_number(n, &p, &q))
			printf("%" PRIu64 "=%" PRIu64 "*%" PRIu64 "\n", n, p, q);
		else
			printf("%" PRIu64 " is prime\n", n);
	}

	fclose(file);
}
