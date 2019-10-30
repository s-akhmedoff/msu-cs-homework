//
// Created by sakhmedoff on 30.10.2019.
//

#ifndef MYSANDBOX_WORKER_H
#define MYSANDBOX_WORKER_H

#endif //MYSANDBOX_WORKER_H

typedef struct {
    char name[20];
    int experience;
    int wag_per_month;
    int total_worked_hours;
    int total_salary;
    int bonus_salary;
} Worker;

char *getName(Worker *w);
int getExperience(Worker *w);
int getWag(Worker *w);
int getHoursWorked(Worker *w);
int getTotalSalary(Worker *w);
int getTotalBonus(Worker *w);