//
// Created by sakhmedoff on 30.10.2019.
//

#include "Controller.h"

#define NL printf("\n")


int _writeToFile(Worker *w, FILE *fp)
{
    if(fp == NULL) return false;
    else
    {
        fwrite(w, sizeof(Worker), 1, fp);
        printf("Writing to file is successful done\n");
        return true;

    }
}

Worker _readFromFile(FILE *fp)
{
    Worker localWorker = {};
    if(fp == NULL) {
        return localWorker;
    } else
    {
        fread(&localWorker, sizeof(localWorker), 1, fp);
        printf("Reading from file is successful done\n");
        return localWorker;
    }
}

// New Section

int totalSalary(Worker *w)
{
    w->total_salary=(w->total_worked_hours/24/30)*w->wag_per_month;
    return w->total_salary;
}

int totalBonus(Worker *w)
{
    if(w->total_salary == 0) totalSalary(w);
    else
    {
        if(w->experience >= 1) w->bonus_salary = (int)(w->total_salary*0.05);
        if(w->experience >= 3) w->bonus_salary = (int)(w->total_salary*0.1);
        if(w->experience >= 5) w->bonus_salary = (int)(w->total_salary*0.15);
        else w->bonus_salary = 0;
    }

    return w->bonus_salary;
}

//

bool fullInfo(Worker *w)
{
    if(w == NULL) return false;
    else
    {
        printf("Name of worker: %s", w->name); NL;
        printf("%s's year of experience: %d", w->name, w->experience); NL;
        printf("%s's wag per month: %d", w->name, w->wag_per_month); NL;
        printf("%s's total worked hours: %d", w->name, w->total_worked_hours); NL;
        printf("%s's total salary: %d", w->name, w->total_salary); NL;
        printf("%s's bonus salary: %d", w->name, w->bonus_salary); NL;
        return true;
    }
}
