//
// Created by sakhmedoff on 25.12.2019 @ 03:12:34
//

#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define _wait sleep(2)

void helloWorld();
void findD();
void meanOfThree();
void meterToKilo();
void findRoots();
double D(double a, double b, double c);

int main() {
    helloWorld();

    findD();

    meanOfThree();

    meterToKilo();

    findRoots();

    return 0;
}

void helloWorld() {
    printf("Task 1\nHello World!\n");
    _wait;
}

void findD() {
    double a, b, c;
    printf("Task 2\nEnter coefficients of quad. equation:\na = ");
    scanf("%lf", & a);
    printf("b = ");
    scanf("%lf", & b);
    printf("c = ");
    scanf("%lf", & c);
    printf("D = %.2lf\n", D(a, b, c));
    _wait;
}

void meanOfThree() {
    int a, b, c;
    double mean;
    printf("Task 3\nEnter three elemtents to find mean:\na = ");
    scanf("%d", & a);
    printf("b = ");
    scanf("%d", & b);
    printf("c = ");
    scanf("%d", & c);
    mean = (double)(a + b + c) / 3.0; // TODO
    printf("Mean of '%d' '%d' '%d' is: %.2lf\n", a, b, c, mean);
    _wait;
}

void meterToKilo() {
    double meter, kilometer, temp;
    printf("Task 4\nEnter meters: ");
    scanf("%lf", & meter);
    temp = meter;
    kilometer = meter / 1000.0;
    if (modf(temp, & temp) == 0.000000) printf("%.0lfm = %.3lfKm\n", meter, kilometer);
    else printf("%lfm = %lfKm\n", meter, kilometer);
    _wait;
}

void findRoots() {
    double a, b, c, d, x1, x2;
    printf("Task 5\n");
    while (1) {
        printf("Enter coefficients of quad. equation such as D>0:\na = ");
        scanf("%lf", & a);
        printf("b = ");
        scanf("%lf", & b);
        printf("c = ");
        scanf("%lf", & c);
        if (D(a, b, c) > 0) break;
        else {
            printf("Wrong! Just do it again!\n");
            continue;
        }
    }
    d = D(a, b, c);
    x1 = (-b + sqrt(d)) / (2.0 * a);
    x2 = (-b - sqrt(d)) / (2.0 * a);
    printf("First root (x1) = %.2lf\nSecond root (x2) = %.2lf\n", x1, x2);
    _wait;
}

double D(double a, double b, double c) {
    return pow(b, 2.0) + (-4.0 * a * c);
}
