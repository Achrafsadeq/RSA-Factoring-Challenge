#!/usr/bin/env python3
def factorize(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return i, n // i
    return n, 1  # This case won't happen as per given assumptions

def main():
    import sys
    
    with open(sys.argv[1], 'r') as f:
        numbers = [int(line.strip()) for line in f]
    
    for number in numbers:
        p, q = factorize(number)
        print(f"{number}={p}*{q}")

if __name__ == "__main__":
    main()

