#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

/**
 * factorize - Factorizes a given number into a product of two factors
 * @number: The number to be factorized
 *
 * This function finds the first two factors of the given number and prints
 * them in the format: n=p*q.
 */
void factorize(long long number)
{
	long long p, q;

	for (p = 2; p * p <= number; p++)
	{
		if (number % p == 0)
		{
			q = number / p;
			printf("%lld=%lld*%lld\n", number, q, p);
			return;
		}
	}
	printf("%lld=%lld*1\n", number, number);
}

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector (file name)
 *
 * This program reads numbers from a file and factorizes each of them.
 * The results are printed in the format n=p*q.
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	long long number;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		perror("Error opening file");
		return (1);
	}

	while (fscanf(file, "%lld", &number) == 1)
	{
		factorize(number);
	}

	fclose(file);
	return (0);
}
