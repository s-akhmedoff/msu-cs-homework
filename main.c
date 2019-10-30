//
// Created by sakhmedoff on 30.10.2019.

#include "stdio.h"

#define DEFAULT_RETURN 0

typedef struct {
    char name[20];
    int exp;
    int wag_per_month;
    int worked_h;
} worker;

int salary_all_time(int wag, int worked_hours);
int Bonus(int experience, int all_time_salary);
void write_to_file();
worker read_from_file();

int main(void)
{
    worker worker1;

    // write_to_file(worker1);
    worker1 = read_from_file();

    int sat = salary_all_time(worker1.wag_per_month, worker1.worked_h);
    int bonus = Bonus(worker1.exp, salary_all_time(worker1.wag_per_month, worker1.worked_h));
    printf("%s: %d$", (char *)"Salary",sat);
    printf("\n%s: %d$", (char *)"Bonus", bonus);

    return DEFAULT_RETURN;
}

int salary_all_time(int wag, int worked_hours)
{
    return (int)((worked_hours/8)/25)*wag;
}

int Bonus(int experience, int all_time_salary)
{
    if(experience < 1) { return DEFAULT_RETURN;}
    if(experience >= 1 && experience < 3) { return all_time_salary/100 * 5;}
    if(experience >= 3 && experience < 5) { return all_time_salary/100 * 8;}
    if(experience >= 5 ) { return all_time_salary/100 * 15; }

    return DEFAULT_RETURN;
}

void write_to_file(worker w){
    FILE *file = fopen("../temp_sandbox.dat", "wb");

    if(file == NULL) printf("error");

    fwrite(&w, sizeof(worker), 1, file);

    fclose(file);
}

worker read_from_file(){

    worker w;

    FILE *file = fopen("../temp_sandbox.dat", "rb");

    if(file == NULL) printf("error");

    fread(&w, sizeof(worker), 1, file);

    return w;
}

//

