// Вывести имена и фамилии студентов, чей рост выше заданного

#include <stdio.h>

struct students {
    char name[100];
    char surname[100];
    int height; // рост студента
};

int main() {
    int n; // количество студентов
    scanf("%d", &n);

    struct students student[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%s", student[i].name);
        scanf("%s", student[i].surname);
        scanf("%d", &student[i].height);
    }

    int limit;  // заданный рост
    scanf("%d", &limit);

    for (int i = 0; i < n; i++) {
        if (student[i].height > limit) {
            printf("%s, %s\n", student[i].name, student[i].surname);
        }
    }

    return 0;

}
