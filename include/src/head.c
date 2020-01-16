#include <stdio.h>
#include "head.h"

void readArray(int16_t* arr, int16_t k);
int16_t checkNumber(int16_t k);
void readDimArray(int16_t** arr, int16_t k, int16_t l);
void printDimArray(int16_t** arr, int16_t k, int16_t l);

int16_t n, x, y;
int16_t* array;
int16_t** dim_array;

int16_t checkNumber(int16_t k)
{
    k = 0;
    while(k < 2)
    {
        puts("Length should be positive and more than 2\nWrite length of array:");
        scanf("%hi", &k);
    }
    return k;
}

void readArray(int16_t* arr, int16_t k)
{
    puts("Enter array elements:");

    for (register int16_t i = 0; i < k; ++i)
        scanf("%hi", arr + i);
}

void readDimArray(int16_t** arr, int16_t k, int16_t l)
{
	puts("Enter elements of 2-Dim array:");
	for(register int i = 0; i < k; i++)
	{
		for(register int j = 0; j < l; j++)
		{
			scanf("%hi", &arr[i][j]);
		}
	}

}

void printDimArray(int16_t** arr, int16_t k, int16_t l)
{
	for(register int i = 0; i < k; i++)
	{
		for(register int j = 0; j < l; j++)
		{
			printf("|%hi|\t", arr[i][j]);
		}
		printf("\n");
	}
}