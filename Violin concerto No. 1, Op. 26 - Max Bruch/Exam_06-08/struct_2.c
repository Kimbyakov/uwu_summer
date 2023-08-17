// Вывести имена студентов, чья оценка выше средней

#include <stdio.h>
#include <stdlib.h>

struct students {
    char name[100];
    int mark;  // оценка
};


int main() {

    int n;
    scanf("%d", &n);
    
    struct students student[n];

    for (int i = 0; i < n; i++) {
        scanf("%s", student[i].name);
        scanf("%d", &student[i].mark);
    }

    int summa = 0;

    for (int i = 0; i < n; i++) {
        summa += student[i].mark;
    }

    int average;
    average = summa / n;

    int counter = 0;

    for (int i = 0; i < n; i++) {
        if (student[i].mark > average) {
            if (counter == 0) {
                printf("%s", student[i].name);
            } else {
                printf(", %s", student[i].name);
            }
            counter++;
        }
    }
}
