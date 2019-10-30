//
// Created by sakhmedoff on 30.10.2019.
//
#include "worker.h"

char *getName(Worker *w)
{
    return w->name;
}
int getExperience(Worker *w)
{
    return w->experience
}
int getWag(Worker *w)
{
    return w->wag_per_month;
}
int getHoursWorked(Worker *w)
{
    return w->total_worked_hours;
}
int getTotalSalary(Worker *w)
{
    return w->total_salary;
}
int getTotalBonus(Worker *w)
{
    return w->bonus_salary;
}