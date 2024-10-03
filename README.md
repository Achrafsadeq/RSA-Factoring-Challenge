# 0x06. RSA Factoring Challenge

## Description

This project focuses on solving the RSA Factoring Challenge by factoring large natural numbers into two smaller factors. The tasks reinforce concepts of number theory and prime factorization, which are essential in cryptography, especially in RSA encryption. By the end of this project, you will have experience in creating efficient scripts or programs to factorize numbers and potentially decode encrypted documents.

## Requirements

| Category | Details |
|----------|---------|
| Editors | `vi`, `vim`, `emacs` |
| OS | Ubuntu 20.04 LTS |
| File Endings | All files should end with a new line |
| README | A `README.md` file at the root of the project folder is mandatory |
| Coding Style | Follow language-specific guidelines (e.g., PEP8 for Python) |
| Global Variables | Not allowed |
| External Libraries | Not allowed (pure code implementations only) |
| Execution Time | Programs should terminate within 5 seconds |
| File Format | All scripts should be executable |

## Project Guidelines

- Each task should factorize natural numbers greater than 1.
- Scripts should read from files containing one natural number per line.
- Output should be in the format `n=p*q` where `p` and `q` are factors of `n`.
- The program must handle numbers of varying sizes efficiently.
- Documentation for each module, function, and method is mandatory.

## Tasks

| Task | Description | File |
|------|-------------|------|
| 0 | Factorize numbers into a product of two smaller factors. | `factors` |
| 1 | Factorize RSA numbers (ensure both factors are prime). | `rsa` |

### Example Task 0:
```bash
$ ./factors tests/test00
4=2*2
12=6*2
34=17*2
128=64*2
```

### Example Task 1:
```bash
$ ./rsa tests/rsa-15
239821585064027=15486481*15485867
```

## Learning Objectives

By the end of this project, you will be able to:

- Understand prime factorization and its importance in cryptography.
- Write efficient scripts to factor large natural numbers.
- Grasp the relevance of RSA encryption and how it relies on large prime factorization.
- Improve your skills in scripting and number theory algorithms.

## Advanced Tasks

| Task | Description | File |
|------|-------------|------|
| 100 | Optimize the factorization for very large numbers. | `factors_advanced` |
| 101 | Optimize RSA factorization for extremely large primes. | `rsa_advanced` |

## Learning Resources

- **Prime Factorization**: Learn how to break down numbers into their prime factors.
- **RSA Encryption**: Understand why large primes are used in RSA and how breaking them compromises security.
- **Efficient Algorithms**: Explore algorithms like the Pollard rho and Fermat's factorization methods.

## Mission Director

This project is supervised by the ALX Software Engineering Program.

## Developer

**Codename**: Achraf Sadeq

## Acknowledgments

Holberton School, in collaboration with the ALX Software Engineering Program, developed this project for educational purposes.
