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

    /* Handle even numbers directly */
    if (n % 2 == 0)
    {
        *p = n / 2;
        *q = 2;
        return (true);
    }

    /* Iterate through odd numbers to find factors */
    for (i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            *p = n / i;
            *q = i;
            return (true);
        }
    }

    /* If no factors found, return false */
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

	/* Read each line, convert it to a number, and factorize */
	while (fgets(line, sizeof(line), file))
	{
		n = strtoull(line, NULL, 10);

		/* Skip numbers less than or equal to 1 */
		if (n <= 1)
			continue;

		/* Factorize and print results */
		if (factorize_number(n, &p, &q))
			printf("%" PRIu64 "=%" PRIu64 "*%" PRIu64 "\n", n, p, q);
		else
			printf("%" PRIu64 " is prime\n", n);
	}

	fclose(file);
}
