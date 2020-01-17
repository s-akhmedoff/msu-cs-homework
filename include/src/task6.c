#include <stdlib.h>
#include <stdio.h>
#include "head.h"
#include "task6.h"

static int16_t isUpperCase(char c);
static int16_t isLowerCase(char c);

void task6(void)
{

	puts("Now executing task 6 - What's more uppercase symbols or lowercase");

	static int upper = 0, lower = 0;
	char ch = 0;

	while(ch != '.')
	{
		scanf("%c", &ch);
		if(isUpperCase(ch) == 1) upper++;
		else if(isLowerCase(ch) == 1) lower++;  
	}

	upper > lower ? puts("UpperCase symbols is more") : puts("LowerCase symbols is more");


}

static int16_t isUpperCase(char c)
{
	char a = 'A';
	while (a++ != 'Z')
	{
		if (c == a) return 1;
	}

	return 0;
}

static int16_t isLowerCase(char c)
{
	char a = 'a';
	while (a++ != 'z')
	{
		if (c == a) return 1;
	}

	return 0;	
}