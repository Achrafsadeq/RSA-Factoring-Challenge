import sys

def factorize(n):
    """Returns a pair of factors of n."""
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return i, n // i
    return n, 1

def main(filename):
    with open(filename, 'r') as file:
        for line in file:
            number = int(line.strip())
            p, q = factorize(number)
            print(f"{number}={p}*{q}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)
    
    main(sys.argv[1])
