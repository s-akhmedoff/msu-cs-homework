#include <stdio.h>
#include <stdlib.h>
#include "task4.h"

int countDigits(char *arr, int k);

void task4(void)
{

	puts("Now executing task 4 - Count numbers in 7th number system in char array");

	int n = 0;
	puts("Length of array:");
	scanf("%d", &n);
	char array[n];

	for(register int i = 0; i < n; ++i)
	{
		if (array[i] != '\n' && array[i] != '.') scanf("%c", array+i);
		else i--;
	}

	printf("Counted %d digits\n", countDigits(array, n));

	n = 0;

}

int countDigits(char *arr, int k)
{
	int result = 0;

	for(register int i = 0; i < k; ++i)
	{
		if ( *(arr+i) == '1' || *(arr+i) == '2' || *(arr+i) == '3' || *(arr+i) == '4' || *(arr+i) == '5' || *(arr+i) == '6') result++;
		else ;
	}

	return result;
}