#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "task7.h"

void max(int16_t** arr, int16_t k, int16_t l);
void min(int16_t** arr, int16_t k, int16_t l);

void task7(void)
{

	puts("Now executing task 7 - Find max and min in 2-Dim Array");

	x = 0; y = 0;
	puts("Write size of 2-Dim Array (X x Y):");
	scanf("%hi %hi", &x, &y);
	
	dim_array = (int16_t**)malloc(x * sizeof(int16_t*));
	for(register int16_t i = 0; i < x; i++)
	{
		dim_array[i] = (int16_t*) malloc(y * sizeof(int16_t));
	}

    readDimArray(dim_array, x, y);
	printDimArray(dim_array, x, y);
	max(dim_array, x, y);
	min(dim_array, x, y);

	for(register int16_t i = 0; i < x; i++)
	{
		free(dim_array[i]);
	}
	free(dim_array);

	x = 0; y = 0;
}

void max(int16_t** arr, int16_t k, int16_t l)
{
	int16_t max = arr[0][0];

	for(register int16_t i = 0; i < k; i++)
	{
		for(register int16_t j = 0; j < l; j++)
		{
			if(arr[i][j] > max) max = arr[i][j];
		}
	}

	printf("Max in 2-Dim array is: %d\n", max);
}

void min(int16_t** arr, int16_t k, int16_t l)
{
	int16_t min = arr[0][0];

	for(register int16_t i = 0; i < k; i++)
	{
		for(register int16_t j = 0; j < l; j++)
		{
			if(arr[i][j] < min) min = arr[i][j];
		}
	}

	printf("Min in 2-Dim array is: %d\n\n", min);
}
