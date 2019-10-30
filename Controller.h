//
// Created by sakhmedoff on 30.10.2019.
//

#ifndef MYSANDBOX_CONTROLLER_H
#define MYSANDBOX_CONTROLLER_H

#endif //MYSANDBOX_CONTROLLER_H
typedef enum {false, true} bool;
#include "worker.h"
#include "stdio.h"

int _writeToFile(Worker *w, FILE *fp);
Worker _readFromFile(FILE *fp);
int totalSalary(Worker *w);
int totalBonus(Worker *w);
bool fullInfo(Worker *w);