// Задача 05_04 (Removing repetitions):

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int number = 0, index = 0, counter = 0, number_of_elements = 1;
    int *data = (int*)malloc(number_of_elements * sizeof(int));

    while (number != -1) {                // пока не конец последовательности

        if (scanf("%d", &number) == 1) {  // если ввод верный
            if (number != -1) {

                if (counter >= number_of_elements) {
                    number_of_elements++;
                    data = (int*)realloc(data, number_of_elements * sizeof(int));
                }

                data[index] = number;
                index++;
                counter++;

            }

        } else {
            printf("n/a");
            break;
        }

    }

    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

    counter = 0;

    for (int i = 0; i < number_of_elements; i++) {
        for (int k = 0; k < 10; k++) {
            if (data[i] == arr[k]) {
                arr[k] = -1;
                if (counter == 0) {
                    printf("%d", data[i]);
                } else {
                    printf(" %d", data[i]);
                }
                counter++;
            }
        }
    }

    return 0;
}
