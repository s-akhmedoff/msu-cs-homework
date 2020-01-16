#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "task10.h"

void sum(int16_t** arr, int16_t k, int16_t l);

void task10(void)
{

	puts("Now executing task 10 - Which sum of pos and neg numbers is more in 2-Dim Array");

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
    sum(dim_array, x, y);

	
	for(register int16_t i = 0; i < x; i++)
	{
		free(dim_array[i]);
	}
	free(dim_array);

	x = 0; y = 0;
}

void sum(int16_t** arr, int16_t k, int16_t l)
{
	int16_t pos = 0; int16_t neg = 0;
	for(register int16_t i = 0; i < k; i++)
	{
		for(register int16_t j = 0; j < l; j++)
		{
			if(arr[i][j] > 0) pos += arr[i][j];
			else if(arr[i][j] < 0) neg += arr[i][j];
		}
	}

	neg = abs(neg);

	pos > neg ? puts("Sum of positive numbers is more") : puts("Sum of negative numbers is more");
}