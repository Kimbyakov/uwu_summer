// Задача 03_04 (Inside the interval):

#include <stdio.h>

int main (void) {

    int a, b, c;
    int result;

    if (scanf("%d %d %d", &a, &b, &c) == 3) {
        result = a < c && c < b;
        printf("%d", result);
    } else {
        printf("n/a");
    }
    
    return 0;
}
