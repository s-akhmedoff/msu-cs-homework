#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "task2.h"

void task2(void) 
{

    puts("Now executing task 2 - Search for element in array that less then neighboors");

    n = checkNumber(n = 0);

    array = (int16_t*) calloc(n, sizeof(int16_t));

    readArray(array, n);

    if ( *(array) < *(array + 1) ) {
        printf("FOUND: %hi at array[0]\n", *(array));
    }

    for (register int16_t i = 1; i < (n - 1); ++i) {
        if ( *(array + i) < *(array + (i - 1)) && *(array + i) < *(array + (i + 1)))
            printf("FOUND: %hi at array[%hi]\n", *(array + i), i);
    }

    if ( *(array + (n - 1)) < *(array + (n - 2)) )
        printf("FOUND: %hi at array[%hi]\n", *(array + (n - 1)), (int16_t)(n-1));

    free(array);
    
    n = 0;

}
