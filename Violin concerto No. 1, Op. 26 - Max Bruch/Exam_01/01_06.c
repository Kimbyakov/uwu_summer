// Задача 01_06 (Исправление ошибок №6):

#include <stdio.h>

int main(void)
{
    int value;
    double pi = 3.141;

    scanf("%d", &value);
    printf("%.2lf", value * pi);

    return 0;
}
