//
// Created by sakhmedoff on 30.10.2019.
#include "stdlib.h"
#include "conio.h"
#include "Controller.h"

#define FILE_LOC "../temp_sandbox.dat"
#define DEFAULT_RETURN 0


int main(void){
    FILE *currentFile = fopen(FILE_LOC, "wb");

    // Write to File
    Worker worker = {"John",5,2500,3000};
    Worker *pworker = &worker;
    totalSalary(pworker);
    totalBonus(pworker);
    _writeToFile(pworker,currentFile);
    free(pworker);
    fclose(currentFile);

    currentFile = fopen(FILE_LOC, "rb");

    // Read from file
    Worker worker1 = _readFromFile(currentFile);
    fclose(currentFile);
    pworker = &worker1;

    // Print full info about worker
    fullInfo(pworker);

    _getch();
    free(pworker);
    free(currentFile);
    return DEFAULT_RETURN;
}

