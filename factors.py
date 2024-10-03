#!/usr/bin/python3

import sys
import math

def read_numbers_from_file(file_path):
    """Reads a list of natural numbers from a file."""
    try:
        with open(file_path, 'r') as file:
            numbers = [int(line.strip()) for line in file]
        return numbers
    except FileNotFoundError:
        print(f"Error: File '{file_path}' not found.")
        sys.exit(1)
    except ValueError:
        print(f"Error: Ensure all lines in '{file_path}' contain valid integers.")
        sys.exit(1)

def trial_division(n):
    """Basic factorization using trial division."""
    if n <= 1:
         n, 1
    for i in range(2, int(math.isqrt(n)) + 1):
        if n % i == 0:
            return i, n // i
    return n, 1  # If n is prime or can't be factored

def factorize_ile_path):
    """Reads numbers from a file and factorizes each one."""
    numbers = read_numbers_from_file(file_path)
    for number in nu:
        p, q = trial_division(number)
        if q == 1:
            print(f"{number} is a prime number.")
        else:
            print(f"{number} = {p} * {q}")

if __name__ == "__main__":
    if len(sys.argv) != 2("Usage: python3 factors.py <file>")
        sys.exit(1)

    input_fil[1]
    factorize_file(input_file)

