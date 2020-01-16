#ifndef HEAD_H_
#define HEAD_H_

typedef signed short int int16_t;

void readArray(int16_t* arr, int16_t k);
int16_t checkNumber(int16_t k);
void readDimArray(int16_t** arr, int16_t k, int16_t l);
void printDimArray(int16_t** arr, int16_t k, int16_t l);

int16_t n, x, y;
int16_t* array;
int16_t** dim_array;

#endif