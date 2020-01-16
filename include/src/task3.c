#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "task3.h"

int16_t power(int16_t a, int16_t b);
void showPoly(int16_t *arr, int16_t k);
int16_t solvePoly(int16_t *arr, int16_t k, int16_t arg_x);

void task3(void)
{

    puts("\nNow executing task 3 - Poly Solver");

    int16_t arg_x = 0;

    n = checkNumber(n = 0);

    array = (int16_t*) calloc(n, sizeof(int16_t));
    readArray(array, n);

    showPoly(array, n);

    puts("Write x: ");
    scanf("%hi", &arg_x);

    printf("Result is: %hi\n", solvePoly(array, n, arg_x));

    free(array);

    n = 0;
}

int16_t power(int16_t a, int16_t b)
{
    int16_t res = 1;
    while(b-- != 0) res *= a;
    return res;
}

void showPoly(int16_t *arr, int16_t k)
{
    
    register int16_t i = k;

    puts("Poly is:");

    while (--i != 1) { // !This shit is working!
        printf("%hi*x^%hi + ", *(arr + i), i);
    }

    printf("%hi*x + %hi\n", *(arr + 1), *(arr + 0));
}

int16_t solvePoly(int16_t *arr, int16_t k, int16_t arg_x)
{

    int16_t polyResult = *(arr+0); // Just store first value of array

    for (register int16_t i = 1; i < k; ++i) {
        polyResult += (int16_t)*(arr + i) * power(arg_x, i);
    }

    return polyResult;
}