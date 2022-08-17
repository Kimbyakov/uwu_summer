# Проверка вводимых данных, как это делать и зочем
## Шаблонный вариат проверки ввода 

Задание: найдите максимальное число из трех введеных целочисленных величин. 
Функцию поиска большего числа оформите отдельной функцией. 

```
#include <stdio.h>

void search_max(int, int, int, int*); 

/* void search_max - это прототип функции. В прототипе функции можно указывать тип передаваемых аргументов, комилятор ссыт на имена типов данных, ибо ему пофиг и вообще эти имена дофига памяти занимают */

int main() {
    int number1, number2, number3, max_number; /*  инициализируем переменные */
    if (scanf("%d %d %d", &number1, &number2, &number3) != 3) { /* смотри ниже пункт 1 */
        printf("n/a\n");
    } else {
        search_max(number1, number2, number3, &max_number);
        printf("%d", max_number);
    }
  return 0;  
  }

  void search_max(int number1, int number2, int number3, int *max_number){
      *max_number = number1
      if(number2 > *max_number){
          *max_number = number2;
      } else if(number3 > *max_number){
          
      }
  }
  ```
  