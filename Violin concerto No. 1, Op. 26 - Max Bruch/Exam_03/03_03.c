// Задача 03_03 (Перестановка крайних цифр):

#include <stdio.h>

int main(void) {

    int x, first, second, third;
    int flag = 1; // True (т.е. число положительное)

    if (scanf("%d", &x) == 1) {  // 159
        
        if (x < 0) {
            flag = 0; // False (т.е. число отрицательное)
            x = -x;
        }

        third = x % 10;   // 9
        x = x / 10;       // 15
        second = x % 10;  // 5
        first = x / 10;   // 1

        if (flag == 1) {
            printf("%d%d%d", third, second, first);
        } else {
            printf("-%d%d%d", third, second, first);
        }
        
    } else {
        printf("n/a");
    }

    return 0;
}
