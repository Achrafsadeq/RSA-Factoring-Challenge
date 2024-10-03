#ifndef FACTOR_H
#define FACTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

/* Function prototypes */
void factorize_file(const char *filename);
bool factorize_number(uint64_t n, uint64_t *p, uint64_t *q);

#endif /* FACTOR_H */
