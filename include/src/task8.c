#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "task8.h"

static void maxColumn(int16_t** arr, int16_t k, int16_t l);

void task8(void)
{

	puts("Now executing task 8 - Find max in columns of 2-Dim Array");

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
    maxColumn(dim_array, x, y);

	for(register int16_t i = 0; i < x; i++)
	{
		free(dim_array[i]);
	}
	free(dim_array);

	x = 0; y = 0;
}

static void maxColumn(int16_t** arr, int16_t k, int16_t l)
{
	int16_t max_in_column = arr[0][0];

	for(register int16_t j = 0; j < l; j++)
	{
		max_in_column = arr[0][j];
		for(register int16_t i = 0; i < k; i++)
		{
			if (arr[i][j] > max_in_column) max_in_column = arr[i][j];
		}
	}

	printf("Max in column is %d\n\n", max_in_column);
}