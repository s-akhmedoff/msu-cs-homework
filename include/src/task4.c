#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "task4.h"

static int16_t countDigits(char *charr, int k);

void task4(void)
{

	puts("Now executing task 4 - Count numbers in 7th number system in char array");

	static int n = 0;
	puts("Length of array:");
	scanf("%d", &n);
	char chars[n];

	for(register int16_t i = 0; i < n; ++i)
	{
		if (chars[i] != '\n' && chars[i] != '.') scanf("%c", chars+i);
		else i--;
	}

	printf("Counted %d digits\n", countDigits(chars, n));

	n = 0;

}

static int16_t countDigits(char *charr, int k)
{
	static int16_t result = 0;

	for(register int16_t i = 0; i < k; ++i)
	{
		if ( *(charr+i) == '1' || *(charr+i) == '2' || *(charr+i) == '3' || *(charr+i) == '4' || *(charr+i) == '5' || *(charr+i) == '6') result++;
		else ;
	}

	return result;
}