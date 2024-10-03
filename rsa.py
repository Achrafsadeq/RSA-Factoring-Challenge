#!/usr/bin/python3
def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def find_prime_factors(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0 and is_prime(i):
            j = n // i
            if is_prime(j):
                return i, j
    return None

def main():
    import sys
    
    with open(sys.argv[1], 'r') as f:
        number = int(f.readline().strip())
    
    p, q = find_prime_factors(number)
    print(f"{number}={p}*{q}")

if __name__ == "__main__":
    main()

