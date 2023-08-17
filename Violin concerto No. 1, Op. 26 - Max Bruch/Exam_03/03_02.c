// Задача 03_02 (Перевод в градусную меру):

#include <stdio.h>
#include <math.h>

int main (void) {

    double radian, degree;

    if (scanf("%lf", &radian) == 1) {
        degree = 57.29 * radian;
        printf("%.0lf", roundf(degree));
    } else {
        printf("n/a");
    }
    
    return 0;
}
