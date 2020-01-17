#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "task9.h"

static void primeRow(int16_t** arr, int16_t k, int16_t l);

void task9(void)
{

	puts("Now executing task 9 - Count Prime and Non-Prime numbers in rows of 2-Dim Array");

	x = 0; y = 0;
    puts("Write size of 2-Dim Array (N x M):");
	scanf("%hi %hi", &x, &y);

	dim_array = (int16_t**)malloc(x * sizeof(int16_t*));
	for(register int16_t i = 0; i < x; i++)
	{
		dim_array[i] = (int16_t*) malloc(y * sizeof(int16_t));
	}

    readDimArray(dim_array, x, y);
	printDimArray(dim_array, x, y);
    primeRow(dim_array, x, y);

	for(register int16_t i = 0; i < x; i++)
	{
		free(dim_array[i]);
	}
	free(dim_array);

	x = 0; y = 0;
}

static void primeRow(int16_t** arr, int16_t k, int16_t l)
{
	int16_t prime_c = 0, nonprime_c = 0;

	for(register int16_t i = 0; i < k; i++)
	{
		for(register int16_t j = 0; j < l; j++)
		{
			if(arr[i][j] % 2 == 0) prime_c++;
			else nonprime_c++;
		}
	}

	printf("Prime counted: %d\nNon Prime counted: %d\n\n", prime_c, nonprime_c);
}