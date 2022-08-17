/* #include <stdio.h>
#include <math.h>


int main () {
    int x, y, z;
    if (scanf("%d%d%d" , &x , &y, &z) == 3) {
        if (x < 0 || x > 1 || y < 0 || y > 1 || z < 0 || z > 1)
        printf("n/a");
    }
    if (x == (y||z)) {
        printf("%d", x);
        return 0;
    }
}
*/

/*
int main () {
    double x;
    if (scanf("%.0lf", &x) != 1) {
        printf("n/a");
        return 1;
    }else {

    double y = x * 57.29;
    double z = round(y);
    printf("%.0lf", z);
    return 0;
    }
     
}

*/


/*
int main()
{
    int x, y, z;
    if (scanf("%d%d%d", &x, &y, &z) == 3)
    {
        if (x < 0 || x > 1 || y < 0 || y > 1 || z < 0 || z > 1)
        {
            printf("n/a");
        return 0;
    }
    if (x == (y||z)) {
        printf("%d", x);
        return 0;
    }
    printf("n/a");
    return 0;
}
}
*/

/*
int main() {
    int x = 0;
    int y1,y2,y3;
    scanf("%d", &x);
    if( x > 0) {
        y1 = x /100;
        y2 = (x/10) %10;
        y3 = x % 10;
        printf("%d%d%d", y3, y2, y1);
    }else{
        x = x * (-1);
        y1 = x /100;
        y2 = (x/10) %10;
        y3 = x % 10;
        printf("-%d%d%d", y3, y2, y1);
    }
    return 0;
}

*/

/*
int main (void) {
        double x;

    if (scanf("%lf", &x) > 1 && getchar() == '\n') {
        printf("n/a");
        return 1;
        }else{
        double y = (57.29 * x);
        double z = round (y);
    printf("%.0lf", z);
}
    return 0;
}
*/

/* 3.01
#include <stdio.h>
#include <math.h>

int main()
{
   double x;
    if ((scanf("%lf", &x) != 1)) {
           printf("n/a");
        }else{
            double y = 21500 * (4.0/3.0) * M_PI * (pow(x,3));
            double result = round (y);
            printf("%.0lf", result);
        }
        return 0;
}

*/

/* 3.02 
#include <stdio.h>
#include <math.h>

int main (void) {
        double x;
    if ((scanf("%lf", &x) != 1)) {
        printf("n/a");
    return 1;
        }else{
        double y = (57.29 * x);
        double z = round (y);
        printf("%.0lf", z);
}
    return 0;
}
*/

/* 3.02(2 variant)
#include <stdio.h>
#include <math.h>

int main (void) {
        double x;
    if ((scanf("%lf", &x) != 1)) {
        printf("n/a");
    return 1;
        }else{
        double y = (57.29 * x);
        double z = round (y);
        printf("%.0lf", z);
}
    return 0;
}
*/

/* 3.03
#include <stdio.h>

int main () {
    int x = 0; // наше число
    int y1,y2,y3; // разделение по разрядам
    scanf("%d", &x);
    if (x>0){
   
            y1 = x/100;
            y2 = (x/10)%10;
            y3 = x %10;
            printf("%d%d%d", y3,y2,y1);
    }
    else {
        x=x*(-1);
        y1 = x/100;
            y2 = (x/10)%10;
            y3 = x %10;
            printf("-%d%d%d", y3,y2,y1);
    }

    return 0;
}
*/

/* 3.05
#include <stdio.h>
int main()
{
    int x, y, z;

    if (scanf("%d%d%d", &x, &y, &z) == 3)
    {
        if (x < 0 || x > 1 || y < 0 || y > 1 || z < 0 || z > 1)
        {
            printf("n/a");
            return 0;
        }
        if (x == (y || z)){
            printf("%d", x);
            return 0;
            }
    }
    printf("n/a");
    return 0;
}
*/

/* 4.02
#include <stdio.h>

int max(int *data, int *m);
// int output(int *a, int *m);
int main() {
  int df;
  int data[100000];

  if (scanf("%d", &df) != 1) {
    printf("n/a");
    return (0);
  }
  int i = 0;
  while (df != -1) {
    data[i] = df;
    scanf("%d", &df);
    i++;
  }
  int max_value = data[0];
  for (int j = 0; j < i; j++) {
    if (data[j] > max_value) {
      max_value = data[j];
    }
  }
  printf("%d", max_value);
}
*/

/* 5.02
#include <stdio.h>

int main() {
  int df;
  int data[100000];

  int i = 0;
  if (scanf("%d", &df) != 1) {
    printf("n/a");
    return (0);
  }
  while (df != -1) {
    data[i] = df;
    scanf("%d", &df);
    i++;
  }
  int max_value = 0;
  int min_value = 0;
  for (int j = 0; j < i; j++) {
    if (data[j] > data[max_value]) {
      max_value = j;
    }
    if (data[j] < data[min_value]) {
      min_value = j;
    }
  }
  int tmp = data[min_value];
  data[min_value] = data[max_value];
  data[max_value] = tmp;
  for (int j = 0; j < i - 1; j++) {
    printf("%d ", data[j]);
  }
  printf("%d", data[i - 1]);
}
*/

/* 5.03
#include <stdio.h>
// #define N_MAX 10000;

int main() {
  double df;

  // int m;
  int data[10000];

  if (scanf("%lf", &df) != 1) {
    printf("n/a");
    return (0);
  }
  int i = 0;
  while (df != -1) {
    data[i] = df;
    scanf("%lf", &df);
    i++;
  }
  printf("%d\n", i);
  int size = i;
  //int j = size;

  for (int k = 0; k < size ; k += 1) {
    if (k == 0) {
        printf("%d", data[k]);
    } else {
        printf(" %d", data[k]);
    }
    if (size - 1 > k) {
      printf(" %d", data[size - 1]);
      size--;
    }
  }
  return (0);
}
*/

/* 5.04
#include <stdio.h>
#include <stdlib.h>

int main(){
    int size = 1;
    int counter = 0;
    char c ;
    int *data = (int*) malloc(size * sizeof(int));
    while (c != '\n'){
        counter++;
        if(counter > size){
            size *= 2;
            data = (int* )realloc(data, size * sizeof(int));
        }
        scanf("%d%c", &data[counter - 1], &c);
        
    }
    for(int i = 0; i < counter; i++){
        if(i == counter -1){
            printf("%d", data[i]);
        }else{
        printf("%d ", data[i]);   
        }
    }
    return 0;
}   
*/

/*

Задания для решений: 
5 - вывести матрицу с числами от 1 до н^2 по змейке из левого верхнего угла в центр (как на степике)
4 - повернуть матрицу на 90 градусов по часовой стрелке 
3 - вывести массив неопределенной длины (ввод заканчивается на -1) задом наперед 
2 - перевести радианы (действительное число) в градусы (целое число)
1 - вывести строчку, где внутри есть " и '

3 - поменять Макс и мин в массиве, заканчивающемся на -1

1. Исправить программу, там чёт простое, типа int pi = 3.14 было
2. Перевести из радианов в градусы (проверка на то, что радианы >=0 НЕ НУЖНА, проверено мистейком)
3. Дано целое число, вывести максимальную его цифру
4. Есть матрица, надо поменять местам строки, содержащие первые вхождения максимального и минимального элементов матрицы
5. На вход подаётся положительное число, надо вывести матрицу, заполненную числами от 1 до n^2 по спирали, типа
1 2 3
8 9 4
7 6 5

*/