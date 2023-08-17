// Задача 03_01 (Платиновый шар):

#include <stdio.h>
#include <math.h>

int main (void) {

    double R, m, result;

    if (scanf("%lf", &R) == 1) {
        m = 21500 * (4.0 / 3.0) * M_PI * pow(R, 3);
        result = round(m);
        printf("%.0lf", result);
    } else {
        printf("n/a");
    }
    
    return 0;
}
