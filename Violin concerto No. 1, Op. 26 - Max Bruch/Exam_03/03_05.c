// Задача 03_05 (логическое выражение):

#include <stdio.h>

int main (void) {

    int x, y, z, result;

    if ((scanf("%d %d %d", &x, &y, &z) == 3) && (x == 0 || x == 1) && (y == 0 || y == 1) && (z == 0 || z == 1)) {
        result = x && (y || z);
        printf("%d", result);
    } else {
        printf("n/a");
    }

    return 0;
}
