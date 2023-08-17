// Задача 05_05 (Реверс последовательности):

#include <stdio.h>
#include <stdlib.h>

int main() {

    int number = 0;
    int index = 0;
    int number_of_elements = 1;
    int *data = (int*)malloc(number_of_elements * sizeof(int));

    if (data != NULL) {  // если память выделилась

        int flag = 1;  // True - предполагаем верный ввод
        
        while (number != -1) {  // пока не конец последовательности

            if (scanf("%d", &number) == 1 && number >= -1) {  // если ввод верный

                if (number != -1) {
                    number_of_elements++;
                    data = (int*)realloc(data, number_of_elements * sizeof(int));
                    data[index] = number;
                    index++;
                }

            } else {
                flag = 0;  // False
                break;
            }

        }

        if (flag) {

            for (int i = index - 1; i >= 0; i--) {
                printf("%d", data[i]);
                if (i != 0) {
                    printf(" ");
                }
            }

        } else {
            printf("n/a");
        }

        free(data);
    
    } else {
        printf("Error - memory wasn't allocated");
    }
    
    return 0;
}
