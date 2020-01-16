#include <stdio.h>
#include <stdlib.h>
#include "task1.h"
#include "head.h"

int16_t countPrime(int16_t* arr, int16_t k);

void task1(void)
{

    puts("Now executing task 1 - Count prime numbers in array");

    n = 0;
    while (n < 1)
    {
        puts("Length should be positive and more than 1\nWrite length of array:");
        scanf("%hi", &n); 
    }
    
    array = (int16_t*) calloc(n, sizeof(int16_t));

    readArray(array, n);

    int16_t count_primes = countPrime(array, n);

    printf("Count of prime number is array is: %hi\n\n", count_primes);

    free(array);
    
    n = 0;

}

int16_t countPrime(int16_t *arr, int16_t k)
{

    int16_t result = 0;

    for (register int16_t i = 0; i < k; ++i)
        if ( (*(arr + i) & 1) != 0) ; // Logical method
        else result++;

    return result; 
}