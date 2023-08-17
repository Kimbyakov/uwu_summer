// Задача 04_01 (Биномиальные коэффициенты):

#include <stdio.h>

int factorial(int n);

int main(void) {

    int n;
    scanf("%d", &n);

    for (int k = 0; k <= n; k++) {

        printf("%d", factorial(n) / (factorial(k) * factorial(n - k)));

        if (k != n) {
        	printf(" ");
        }
    }

    return 0;
}

int factorial(int n) {

    int s = 1;

    for (int i = 1; i <= n; i++) {
        s *= i;
    }

    return s;
}
