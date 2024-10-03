#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * gcd - Calculate the greatest common divisor of two numbers
 * @a: First number
 * @b: Second number
 *
 * Return: The greatest common divisor of a and b
 */
long long gcd(long long a, long long b)
{
	if (b == 0)
		return (a);
	return (gcd(b, a % b));
}

/**
 * pollards_rho - Implement the Pollard's rho algorithm for factorization
 * @n: Number to factorize
 *
 * Return: A factor of n
 */
long long pollards_rho(long long n)
{
	if (n % 2 == 0)
		return (2);

	long long x = rand() % (n - 2) + 2;
	long long y = x;
	long long c = rand() % (n - 1) + 1;
	long long d = 1;

	while (d == 1)
	{
		x = (x * x + c) % n;
		y = (y * y + c) % n;
		y = (y * y + c) % n;
		d = gcd(llabs(x - y), n);

		if (d == n)
			return (pollards_rho(n));
	}

	return (d);
}

/**
 * factorize - Factorize a number and print the result
 * @n: Number to factorize
 */
void factorize(long long n)
{
	if (n == 1)
	{
		printf("1=1*1\n");
		return;
	}

	long long factor = pollards_rho(n);

	if (factor == n)
		printf("%lld is prime\n", n);
	else
		printf("%lld=%lld*%lld\n", n, factor, n / factor);
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
		long long n = atoll(line);

		factorize(n);
	}

	fclose(file);
	if (line)
		free(line);

	return (0);
}
