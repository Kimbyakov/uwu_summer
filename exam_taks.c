/* Task 1 - Своп максимальных и минимальных значений матрицы */

#include <stdio.h>

int main() {

  int M, N;

  if (scanf("%d", &M) != 1) {
    printf("n/a");
    return 1;
  }

  if (scanf("%d", &N) != 1) {
    printf("n/a");
    return 1;
  }

  int a[M][N];

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  int max_i = 0, min_i = 0, max = a[0][0], min = a[0][0];

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (a[i][j] > max) {
        max = a[i][j];
        max_i = i;
      }
      if (a[i][j] < min) {
        min = a[i][j];
        min_i = i;
      }
    }
  }

  for (int j = 0; j < N; j++) {
    int tmp = a[max_i][j];
    a[max_i][j] = a[min_i][j];
    a[min_i][j] = tmp;
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (j < N - 1) {
        printf("%d ", a[i][j]);
      } else {
        printf("%d", a[i][j]);
        printf("\n");
      }
    }
  }
}


=====================================================================
/* Task 3 - На вход подается строка, является она палиндромом или нет 
Вариант 1
*/
	
#include <stdio.h>
#include <string.h>

int main(){
    char word[200];
    int len = 0;
    int flag = 0;

    while(scanf("%c", &word[len]) == 1 && word[len] != '\n') {
        if (word[len] >= 'a' && word[len] <= 'z')
            word[len] -= 32;
        len++;
    }

    
    for(int i=0;i < len ;i++){
        if(word[i] != word[len-i-1]){
            flag = 1;
            break;
           }
        }
    
    if (flag) {
        printf("NO");
    }    
    else {
        printf("YES");
    }
    return 0;
}

Вариант 2

#include <stdio.h>
#include <string.h>
int main() {
  char string[25], reverse_string[25] = {'\0'};
  int i, length = 0, flag = 0;
  scanf("%s", string);
  for (i = 0; string[i] != '\0'; i++) {
    length++;
  }
  for (i = length - 1; i >= 0; i--) {
    if (string[i] < 91)
      string[i] = string[i] + 32;
    reverse_string[length - i - 1] = string[i];
  }
  for (flag = 1, i = 0; i < length; i++) {
    if (reverse_string[i] != string[i])
      flag = 0;
  }
  if (flag == 1)
    printf("YES");
  else
    printf("NO");
}
*/

=====================================================================
/* Task 4 - Умножение матриц*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;
  char term;

  if (scanf("%d%c", &N, &term) != 2 || term != '\n') {
    printf("n/a");
    return 1;
  }

  int A[N][N];
  int B[N][N];
  int C[N][N];

  //   int **A = (int **)malloc(N * sizeof(int *));
  //   int **B = (int **)malloc(N * sizeof(int *));
  //   int **C = (int **)malloc(N * sizeof(int *));

  //   for (int i = 0; i < N; i++) {
  //     A[i] = (int *)malloc(N * sizeof(int));
  //     B[i] = (int *)malloc(N * sizeof(int));
  //     C[i] = (int *)malloc(N * sizeof(int));
  //   }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      if (scanf("%d", &A[i][j]) != 1) {
        printf("n/a");
        return 1;
      }
    }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      if (scanf("%d", &B[i][j]) != 1) {
        printf("n/a");
        return 1;
      }
    }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      C[i][j] = 0;
      for (int k = 0; k < N; k++)
        C[i][j] += A[i][k] * B[k][j];
    }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j < N - 1) {
        printf("%d ", C[i][j]);
      } else {
        printf("%d", C[i][j]);
        printf("\n");
      }
    }
  }
}


========================================================================
/* Task 5 - Перевод в верхний регистр первого символа каждого слова

Написать программу, осуществляющую перевод в верхний регистр 
первого символа каждого слова, разделенного пробелами в строке.
Строка, заканчивающаяся символом новой строки \n, задается на 
стандартном потоке ввода stdin и состоит из букв латинского алфавита,
цифр и пробелов, которые разделяют слова между собой. Преобразованную
строку вывести на стандартный поток вывода stdout. В конце ответа не 
должно быть переноса на новую строку.

Пример:			This is my time --> This Is My Time
			area1234 --> Area1234
----------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

void output(size_t i, char* array);
void change_reg(size_t i, char* array);

int main() {
    char* array = NULL;
    size_t i = 0;
    char box;
    while (scanf("%c", &box) != 0 && box != '\n') {
        array = realloc(array, (i + 1) * sizeof(char));
        array[i] = box;
        i++;
    }
    array[i] = '\0';
    change_reg(i, array);
    output(i, array);
    free(array);
    return 0;
}

// поиск  буквы в нижнем регистре и замена ее на букву в верхнем регистре
void change_reg(size_t i, char* array) {
    size_t j = 0;
    while (j < i) {
        if (array[0] < 123 && array[0] > 96) {
            array[0] = array[0] - 32;
        }
        if (array[j] == ' ') {
            if (array[j + 1] < 123 && array[j + 1] > 96) {
                array[j + 1] = array[j + 1] - 32;
            }
        }
        j++;
    }
}

// вывод нового массива в терминале
void output(size_t i, char* array) {
    size_t f = 0;
    while (f < i) {
        printf("%c", array[f]);
        f++;
    }
}

=====================================================================
/* Task 6 

На вход подаётся три числа. Гарнтируется, что 
подаются только целые числа. Необходимо написать программу, 
которая бы выводила 1, если третье число массива расположено 
между первым и вторым. Не использовать if.


Пример ввода : 0 9 5
Пример вывода: 1
Пример ввода: 1 2 3
Пример вывода : 0
--------------------------------------------------------------- */
	
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int result;
    int array[3];
    int i = 0;
    while (i < 3) {
        scanf("%d", &array[i]);
        i++;
    }
    result = (array[2] > array[0] && array[2] < array[1]) || (array[2] < array[0] && array[2] > array[1]);
    printf("%d", result);
    return 0;
}



=====================================================================
/* Task 7 - Вывести число в обратном порядке*/

#include <stdio.h>

int main() {
    int a;
    if (scanf("%d", &a)) {
            int b = a%10;
            int c = a / 10;
            int d = c%10;
            int e = c / 10;
            int f = e%10;
        if (a >= 0) {
            printf("%d%d%d", b, d, f);
        }
        if (a < 0) {
            printf("-%d%d%d", b * (-1), d * (-1), f * (-1));
        }
    }
    return 0;
}
*/

=====================================================================
/* Task 8 

Дана последовательность чисел. Конец последовательности -1. 
Вывести в порядке Вывести x1 xn x2 xn-1 x3 xn-2 и так далее
Реализация через динамический массив */
--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *str = malloc(1 * sizeof(int));
    int k = 0;
    int flag = 0;
    while(scanf("%d", &str[k]) == 1 && str[k] != -1) { // считываем строку
        int *tmp = realloc(str, k + 1);
        if (tmp == NULL) {
            flag = 1;
        } else {
        str = tmp;
        k++;
        }
    }

    if (flag == 0) {
    int *output = malloc((k + 1) * sizeof(int));
    int j = 0;
    for(int i = 0; i < k; i += 2)   { // записываем элементы с начала
        output[i] = str[j];
        j++;
    }

    j = k - 1;
    for(int i = 1; i < k; i += 2)   { // записываем элементы с конца
        output[i] = str[j];
        j--;
    }

    free(str);

    for(int i = 0; i < k; i++) {
        printf("%d ", output[i]);  // печатаем массив
    }

    free(output);
    }

    return 0;
}

=====================================================================
/* Task 9 - Дана последовательность чисел. Конец последовательности -1. Вывести в порядке Вывести x1 xn x2 xn-1 x3 xn-2 и так далее
Реализация через статик массив */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int str[1000];
    int output[1000];
    int k = 0;
    while(scanf("%d", &str[k]) == 1 && str[k] != -1) { // считываем строку
        k++;
    }

    int j = 0;
    for(int i = 0; i < k; i += 2)   { // записываем элементы с начала
        output[i] = str[j];
        j++;
    }

    j = k - 1;
    for(int i = 1; i < k; i += 2)   { // записываем элементы с конца
        output[i] = str[j];
        j--;
    }

    for(int i = 0; i < k; i++) {
        printf("%d ", output[i]);  // печатаем массив
    }
    return 0;
}
*/

=====================================================================
/* Task 10 - Факториал - реализация через статик массив */

#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main() {
    int n;
    if(scanf("%d", &n) == 1) {
    n = n + 1;
    int arr[N][N];
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }

    arr[0][0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                arr[i][j] = 1;
            } else {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }

    for (int j = 0; j < n; j++) {
        printf("%d ", arr[n - 1][j]);
    }
    return 0;
    }
}

=====================================================================
/* Task 11 - Задача перевода радиуса шара в радианы	

Найти массу шара. Радиус шара вводиться в консоль ( радиус имеет тип double).
Плотность шара = 21500 кг/м^3
Даны формулы:
V = (4/3) * pi * R^3
P = m / V
Вывести массу округлив ее до целого числа математически верно.
Примечание:
Использовать константу M_PI, и функцию double round(double) из библиотеки math.h
Вывод должен выглядеть так:
printf("%.0lf", result); 
r = 1, 10.    

1. Посчитать обьем шара
2. Вывести формулу массы, посчитать
3. Вывести результат
4. Сделать проверку на корректность ввода
5. Cpplint
6. Test for leaks 
-------------------------------------------------------------------------*/
Вариант 1
	
#include <stdio.h>
#include <math.h>

int main() {
    // float density_of_the_sphere = 21500 кг/м^3 = 0,0215 кг/см^3
    double r = 0.0;
    char endline;
    if (scanf("%lf", &r)) {
        endline = getchar();
        if (endline == ' ' || endline == '\n') {
            double v = (4.0/3.0) * M_PI * pow(r, 3.0);
            double p = 0.0215;
            double m = p * v;
            double rounded_mass = round(m);
            printf("%lf\n", m);
            printf("%0lf", rounded_mass);
            } else {
                printf("n/a");
            }
    } else {
        printf("n/a");
    }
    return 0;
}


========  Вариант 2

#include <math.h>
#include <stdio.h>

int main() {
  int p = 21500;
  double r;
    if (scanf("%lf", &r) == 1) {
      double v = (4. / 3.) * M_PI * pow(r, 3);
      double m = p * v;
      double rounded_mass = round(m);
      printf("%.0lf", rounded_mass);
    } else {
      printf("n/a");
      return 0;
    }
}

=====================================================================
/* Task 12 - Транспонирование матрицы	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	scanf_s("%d", &n);
	int** pointer = malloc(n * sizeof(int*));
	int* value = malloc(n * n * sizeof(int));

	for (int i = 0; i < n; i++) {
		pointer[i] = value + n * i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &pointer[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", pointer[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int** pointer_trans = malloc(n * sizeof(int*));
	int* value_trans = malloc(n * n * sizeof(int));

	for (int i = 0; i < n; i++) {
		pointer_trans[i] = value_trans + n * i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pointer_trans[i][j] = pointer[j][i];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", pointer_trans[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int** p = malloc(n * sizeof(int*));
	int* v = malloc(n * n * sizeof(int));

	for (int i = 0; i < n; i++) {
		p[i] = v + n * i;
	}

	int k = 0, l = 0, m = 0;
	for (m = 0; m < n; m++) {
		for (k = 0; k < n; k++) {
			p[m][k] = 0;
			for (l = 0; l < n; l++) {
				p[m][k] += pointer_trans[m][l] * pointer[l][k];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	free(value);
	free(pointer);
	free(value_trans);
	free(pointer_trans);
	free(v);
	free(p);
	return 0;
}

=====================================================================
/* Task 13 - Дана последовательность целх числе. Число н. Символ конца -1. 
Вывести х1 хн х2 хн-1 х3 хн-2	*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int kArrayLenght = 2, counter_for_output, temp, *pointer_to_the_array;
    pointer_to_the_array = (int*)malloc(sizeof(int));
    if (pointer_to_the_array == NULL) {
        printf("n/a");
        return 1;
    } else {
        for (int i = 0; i < kArrayLenght; i++) {
            if (!scanf("%d", &temp)) {
                printf("n/a");
                return 1;
            } else if (temp == -1) {
                kArrayLenght = i;
            } else {
                pointer_to_the_array[i] = temp;
                kArrayLenght += 1;
                pointer_to_the_array = (int*)realloc(pointer_to_the_array, (kArrayLenght)*sizeof(int));
                }
        }
        counter_for_output = kArrayLenght;
        printf("Array of numbers after input:\n");
        for (int i = 0; i < kArrayLenght; i++) {
            printf("%d", pointer_to_the_array[i]);
            if (i < kArrayLenght - 1) {
                printf(" ");
            } else if (i == kArrayLenght - 1) {
                printf("\n");
            }
        }
        printf("Array of numbers multiplied:\n");
        for (int j = 0; j < kArrayLenght; j++) {
            printf("%d", pointer_to_the_array[j] * counter_for_output);
            counter_for_output--;
            if (j < kArrayLenght - 1) {
                printf(" ");
            }
        }
    }
    free(pointer_to_the_array);
}

=====================================================================
/* Task 14 - Умножение матрица через динамический массив	*/

#include <stdio.h>
#include <stdlib.h>

void read_matrix(int **matrix, int *pflag, int N);

int main() {
  int N, flag = 0;
  if (scanf("%d", &N) == 1 && N > 0) {
    int **matrix1, **matrix2;

    matrix1 = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
      matrix1[i] = malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        flag = scanf("%d", &matrix1[i][j]);
      }
    }

    matrix2 = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
      matrix2[i] = malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        flag = scanf("%d", &matrix2[i][j]);
      }
    }

    if (flag == 0) {
      printf("n/a");
    } else {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          int sum = 0;
          for (int k = 0; k < N; k++) {
            sum += matrix1[i][k] * matrix2[k][j];
          }
          printf("%d", sum);
          if (j != N - 1) {
            printf(" ");
          }
        }
        if (i != N - 1) {
          printf("\n");
        }
      }
    }

    for (int i = 0; i < N; i++) {
      free(matrix1[i]);
      free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
  } else {
    printf("n/a");
  }
  return 0;
}

=====================================================================
/* Task 15 - Умножение матриц через статик	*/

#include <stdio.h>

int main() {
  int N, flag = 0;
  if (scanf("%d", &N) == 1 && N > 0) {
    int matrix1[N][N], matrix2[N][N];

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        flag = scanf("%d", &matrix1[i][j]);
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        flag = scanf("%d", &matrix2[i][j]);
      }
    }

    if (flag == 0) {
      printf("n/a");
    } else {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          int sum = 0;
          for (int k = 0; k < N; k++) {
            sum += matrix1[i][k] * matrix2[k][j];
          }
          printf("%d", sum);
          if (j != N - 1) {
            printf(" ");
          }
        }
        if (i != N - 1) {
          printf("\n");
        }
      }
    }
  } else {
    printf("n/a");
  }
  return 0;
}

=====================================================================
/* Task 16 - Задание с пробелом	*/

#include <stdio.h>
#include <string.h>
int main() {
    char string[100];
    char new[100];
    fgets(string, 256, stdin);
    int j = 0;
    for (int i = 0; i < (int)strlen(string); i++) {
        if (string[i] == ' ') {
            if (string[i+1] == ' ' || j == 0 || string[i+1] == '\0') {continue;}
        }
        new[j] = string[i];
        j++;
    }
    new[j-2] = '\0';
    printf("%s", new);
}

=====================================================================
/* Task 17 - Своп максимума и минимума через реалок	*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	char *matrix = NULL;
	int elem, i = 0;
	while (scanf_s("%d", &elem) == 1 && elem != -1) {
		matrix = realloc(matrix, (i + 1) * sizeof(int));
		matrix[i] = elem;
		i++;
	}
	int count = i - 1;

	// reverse output

	printf("%d", matrix[count]);
	for (int j = count - 1; j >= 0; j--) {
		printf(" %d", matrix[j]);
	}

	printf("\n");

	// swap first min first max

	int max = matrix[0];
	int min = matrix[0];
	int cmin, cmax;

	for (int k = 0; k <= count; k++) {
		if (matrix[k] < min) {
			min = matrix[k];
		}
	}

	int k = 0;
	while (k <= count) {
		if (matrix[k] == min) {
			cmin = k;
			break;
		}
		k++;
	}

	for (int k = 0; k <= count; k++) {
		if (matrix[k] > max) {
			max = matrix[k];
		}
	}

	k = 0;
	while (k <= count) {
		if (matrix[k] == max) {
			cmax = k;
			break;
		}
		k++;
	}

	matrix[cmax] = min;
	matrix[cmin] = max;

	printf("%d", matrix[0]);
	for (int j = 1; j <= count; j++) {
		printf(" %d", matrix[j]);
	}

	printf("\n");

	// sort

	int temp;
	for (int i = 0; i <= count - 1; i++) {
		for (int j = 0; j <= count - i - 1; j++) {
			if (matrix[j + 1] < matrix[j]) {
				temp = matrix[j];
				matrix[j] = matrix[j + 1];
				matrix[j + 1] = temp;
			}
		}
	}

	printf("%d", matrix[0]);
	for (int j = 1; j <= count; j++) {
		printf(" %d", matrix[j]);
	}

	free(matrix);
	return 0;
}

=====================================================================
/* Task 18  

Написать программу, осуществляющую удаление повторяющихся элементов в последовательности, 
состоящей из целых неотрицательных чисел. (Концом последовательности считать -1)
Порядок элементов в результирующей последовательности должен соответствовать 
порядку первых вхождений соответствующих чисел в исходной последовательности  */
---------------------------------------------------------------------	
	
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *str = malloc(1 * sizeof(int));
  int k = 0;
  int flag = 0;
  while (scanf("%d", &str[k]) == 1 && str[k] != -1) { // считываем строку
    int *tmp = realloc(str, k + 1);
    if (tmp == NULL) {
      flag = 1;
    } else {
      str = tmp;
      k++;
    }
  }

  if (flag == 0) {

    int *out = calloc(k + 1, sizeof(int));
    int n = 0;
    for (int i = 0; i < k + 1; i++) {
      int counter = 0;
      for (int j = 0; j < k + 1; j++) {
        if (str[i] == out[j]) {
          counter++;
        }
      }
      if (counter == 0 && str[i] != -1) {
        out[n] = str[i];
        n++;
      }
    }
    for (int i = 0; i < n; i++) {
      printf("%d ", out[i]);
    }
    free(out);
  }
  free(str);
  return 1;
}

=====================================================================
/* Task 19 - Rotate matrix with malloc	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	int** pointer = malloc(n * sizeof(int*));
	int* value = malloc(n * n * sizeof(int));

	for (int i = 0; i < n; i++) {
		pointer[i] = value + n * i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &pointer[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", pointer[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int** p = malloc(n * sizeof(int*));
	int* v = malloc(n * n * sizeof(int));

	for (int i = 0; i < n; i++) {
		p[i] = v + n * i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			p[i][n - 1 - j] = pointer[j][i];
		}
	}

    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	free(value);
	free(pointer);
	free(v);
	free(p);
	return 0;
}

=====================================================================
/* Task 20 - Snake side to side	*/

#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int my_matrix[n][n];

        int count = 1;
        int dir_ball = 0;
        int x_b = 0;
        int y_b = 0;

        int left = 0;
        int right = n - 1;

        while (count != (n * n + 1)) {
            my_matrix[y_b][x_b] = count;
            count++;

            if (dir_ball == 0) {  // move right
                if (x_b == right) {
                    y_b++;
                    dir_ball = 1;
                } else {
                    x_b++;
                }
            } else if (dir_ball == 1) {  // move left
                if (x_b == left) {
                    y_b++;
                    dir_ball = 0;
                } else {
                    x_b--;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", my_matrix[i][j]);
                if (j < n - 1) {
                    printf(" ");
                }
            }
            if (i < n - 1)
                printf("\n");
        }
    } else {
        printf("n/a");
    }
}

=====================================================================
/* Task 21 - Snake to center	*/

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int my_matrix[n][n];

        int count = 0;
        int dir_ball = 0;
        int x_b = -1;
        int y_b = 0;

        int up = 1;
        int down = n - 1;
        int left = 0;
        int right = n - 1;

        while (count != (n * n + 1)) {
            my_matrix[y_b][x_b] = count;
            count++;

            if (dir_ball == 0) {  // move right
                x_b++;
                if (x_b == right) {
                    right--;
                    dir_ball = dir_ball + 1;
                }
            } else if (dir_ball == 1) {  // move down
                y_b++;
                if (y_b == down) {
                    down--;
                    dir_ball = dir_ball + 1;
                }
            } else if (dir_ball == 2) {  // move left
                x_b--;
                if (x_b == left) {
                    left++;
                    dir_ball = dir_ball + 1;
                }
            } else if (dir_ball == 3) {  // move up
                y_b--;
                if (y_b == up) {
                    up++;
                    dir_ball = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", my_matrix[i][j]);
                if (j < n - 1) {
                    printf(" ");
                }
            }
            if (i < n - 1)
                printf("\n");
        }
    } else {
        printf("n/a");
    }
}

=====================================================================
/* Task 21 - Snake spiral	*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m;
    int i, j = 0;
    char end;

    if(scanf("%d%c", &m, &end) == 2 && end == '\n' && m > 0) { // end для проверки на нецелое число
        int **a = calloc(m, sizeof(int *)); // создаем динамическую матрицу (10 - 13 строки)
        for (int i = 0; i < m; i++) {
            a[i] = calloc(m, sizeof(int));
        }
        int flag = 0; // флаг определяет, в каком направлении по матрице мы движемся (0 - вправо, 1 - вниз, 2 - влево, 3 - вверх)
        int c = 1; // счетчик, значения которого записываем в массив
        while (c <= m * m) {
            if (flag == 0) {
                while (j < m && a[i][j] == 0) {
                a[i][j] = c;
                c++;
                j++;
                }
                j--; // тк прошла лишняя итерация и j выходит за пределы массива, откатываем его на единицу назад
                i++; // спускаемся на строку ниже, чтобы не перезаписать значение в уже заполненную ячейку
                flag = 1;
            } else if (flag == 1) {
                while (i < m && a[i][j] == 0) {
                a[i][j] = c;
                c++;
                i++;
                }
                i--; // откатываемся в пределы массива
                j--; // откат, чтобы не перезаписывать значение
                flag = 2;
            } else if (flag == 2) {
                while (j > -1 && a[i][j] == 0) {
                a[i][j] = c;
                c++;
                j--;
                }
                j++; // откатываемся в пределы массива
                i--; // откат, чтобы не перезаписывать значение
                flag = 3;
            } else if (flag == 3) {
                while (i > -1 && a[i][j] == 0) {
                a[i][j] = c;
                c++;
                i--;
                }
                i++; // откатываемся в пределы массива
                j++; // откат, чтобы не перезаписывать значение
                flag = 0;
            }

        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < m; i++) {
            free(a[i]); // чистим массивы строк
        }
        free(a); // чистим массив указателей
    }
}

=====================================================================
/* Task 23 - Структура - люди	*/

#include <stdio.h>
#define NMAX 20
struct Person {
        char first_name[NMAX];
        char last_name[NMAX];
        int height;
    };
void input(struct Person* people, int number_of_elements);
void output(struct Person* people, int number_of_elements, int h_number);
int main() {
    // Declaration of array named "people" of structure Person
    struct Person people[NMAX];
    int number_of_elements = 0;
    scanf("%d", &number_of_elements);
    input(people, number_of_elements);
    int h_number = 0;
    scanf("%d", &h_number);
    output(people, number_of_elements, h_number);
    
    return 0;
}
void input(struct Person* people, int number_of_elements) {
    for (int i = 0; i < number_of_elements; i++) {
        scanf("%s", people[i].first_name);
        scanf("%s", people[i].last_name);
        scanf("%d", &people[i].height);
    }
}
void output(struct Person* people, int number_of_elements, int h_number) {
    for (int i = 0; i < number_of_elements; i++) {
        if (people[i].height >= h_number) {
            printf("%s ", people[i].first_name);
            printf("%s", people[i].last_name);
            }
        if (i < number_of_elements - 2) {
            printf(", ");
        }
    }
}

=====================================================================
/* Task 24 - Структура имя фамилия рост*/

Вариант 1
#include <stdio.h>

struct data {
    char name[1000];
    char surname[1000];
    int height; 
};

int main() {
    int n; // количество структур
    scanf("%d", &n);
    struct data data[n];
    for (int i = 0; i < n; i++) {
        scanf("%s", data[i].name);
        scanf("%s", data[i].surname);
        scanf("%d", &data[i].height);
    }

    int limit;
    scanf("%d", &limit);

    for (int i = 0; i < n; i++) {
        if (data[i].height > limit) {
            printf("%s, %s\n", data[i].name, data[i].surname);
        }
    }

}

// Вариант 2 

#include <stdio.h>
#define NMAX 20

struct Person {
        char first_name[NMAX];
        char last_name[NMAX];
        int height;
    };

void input(struct Person* people, int number_of_elements);
void output(struct Person* people, int number_of_elements, int h_number);

int main() {

    // Declaration of array named "people" of structure Person
    struct Person people[NMAX];

    int number_of_elements = 0;
    scanf("%d", &number_of_elements);

    input(people, number_of_elements);

    int h_number = 0;
    scanf("%d", &h_number);

    output(people, number_of_elements, h_number);
    
    return 0;
}

void input(struct Person* people, int number_of_elements) {
    for (int i = 0; i < number_of_elements; i++) {
        scanf("%s", people[i].first_name);
        scanf("%s", people[i].last_name);
        scanf("%d", &people[i].height);
    }
}

void output(struct Person* people, int number_of_elements, int h_number) {
    for (int i = 0; i < number_of_elements; i++) {
        if (people[i].height >= h_number) {
            printf("%s ", people[i].first_name);
            printf("%s", people[i].last_name);
            }
        if (i < number_of_elements - 2) {
            printf(", ");
        }
    }
}

=====================================================================
/* Task 25 - Транспонирование матрицы через статик */

#include <stdio.h>

int main() {
    int N, flag = 1;
    if (scanf("%d", &N) == 1 && N > 0) {
        int matrix[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                flag = scanf("%d", &matrix[i][j]);
            }
        }
        if (flag == 0) {
            printf("n/a");
        } else {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    printf("%d", matrix[j][i]);
                    if (j != N - 1) { printf(" "); }
                }
                if (i != N - 1) { printf("\n"); }
            }
        }
    }
	
    return 0;
}

=====================================================================
/* Task 26 - Еще одно транспонирование матрицы	*/

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int my_matrix[n][n];

        int bad = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (scanf("%d", &my_matrix[i][j]) != 1)
                    bad = 1;
                if (bad)
                    break;
            }
            if (bad)
                break;
        }
        if (!bad) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d", my_matrix[j][i]);
                    if (j < n - 1) {
                        printf(" ");
                    }
                }
                if (i < n - 1)
                    printf("\n");
            }
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
}
*/

=====================================================================
/* Task 27 - split the digits	*/

#include <stdio.h>

int main()
{
    int num;
    
    scanf("%d",&num);
    
    while(num > 0) //do till num greater than  0
    {
        int mod = num % 10;  //split last digit from number
        printf("%d\n",mod); //print the digit. 
    
        num = num / 10;    //divide num by 10. num /= 10 also a valid one 
    }
    
    return 0;
}


=====================================================================
/* Task 28 - Биноминальный коэф	*/

#include <stdio.h>

int factorial(int number);
int c_formula(int number, int k);

int main() {
    int number;
    scanf("%d", &number);
    for (int k = 0; k <= number; k++) {
        printf("%d", c_formula(number, k));
        if (k != number) {
            printf(" ");
        }
    }
    return 0;
}

int factorial(int number) {
    int number_to_return = 1;
    for (int i = 1; i <= number; i++) {
        number_to_return *= i;
    }
    return number_to_return;
}

int c_formula(int number, int k) {
    int result = factorial(number) / (factorial(k) * factorial(number - k));
    return result;
}

=====================================================================
/* Task 29 - Структура: студенты */

Build a structure of Students, there is name and lastname and grade of a student
Create a program to output the first and lastname of those students, whose grades are at the top
Output result - "First name, Last name, Second first name, Second last name"
In case of invalid input, output - "n/a"
Maximum length of a name is 20 chars long, total number of students is entered beforehand. The input in entered one line at a time - \n
Grade cannot be negative. Name is a string without spaces and with a newline at the end

+ 1. Build a structure of Students
+ 2. Take input - total number of Students
+ 3. Take input of names and grades 
+ 4. Write a function to count how many of top students are there
+ 5. Write a fucntion to output them to the screen
+ 6. Invalid input
+ 7. Test
+ 8. Cpplint check
+ 9. Push to Github

#include <stdio.h>
#define NMAX 20

struct Students {
    char first_name[NMAX];
    char last_name[NMAX];
    int semester_grade;
};

int input_number_of_students();
int input_names_and_grades(struct Students* array, int number_of_students);
int maximum_grade_of_students(struct Students* array, int number_of_students);
int count_top_grade_students(struct Students* array, int number_of_students, int maximum_grade_value);
void output_names_and_grades_of_top_students(struct Students* array, int number_of_students,
int number_of_top_students, int maximum_grade_value);

int main() {
    int number_of_students = input_number_of_students();
    if (number_of_students > 0) {
        struct Students array[number_of_students];
        if (input_names_and_grades(array, number_of_students) == 0) {
            int maximum_grade_value = maximum_grade_of_students(array, number_of_students);
            int number_of_top_students = count_top_grade_students(array,
            number_of_students, maximum_grade_value);
            output_names_and_grades_of_top_students(array, number_of_students,
            number_of_top_students, maximum_grade_value);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int maximum_grade_of_students(struct Students* array, int number_of_students) {
    int maximum_grade_value = 0;
    for (int i = 0; i < number_of_students; i++) {
        if (maximum_grade_value < array[i].semester_grade) {
            maximum_grade_value = array[i].semester_grade;
        }
    }
    return maximum_grade_value;
}

int count_top_grade_students(struct Students* array, int number_of_students, int maximum_grade_value) {
    int counter = 0;
    for (int j = 0; j < number_of_students; j++) {
        if (array[j].semester_grade == maximum_grade_value) {
            counter++;
        }
    }
    return counter;
}
void output_names_and_grades_of_top_students(struct Students* array, int number_of_students,
int number_of_top_students, int maximum_grade_value) {
    for (int i = 0; i < number_of_students; i++) {
        if (array[i].semester_grade == maximum_grade_value) {
            printf("%s %s %d", array[i].first_name, array[i].last_name, array[i].semester_grade);
            if (i < number_of_top_students) {
                printf(", ");
            }
        }
    }
}

int input_names_and_grades(struct Students* array, int number_of_students) {
    char endline;
    int return_case = 0;
    for (int i = 0; i < number_of_students; i++) {
        if (!scanf("%s%c", array[i].first_name, &endline) || endline != '\n') {
            return_case = 1;
            break;
        }
        if (!scanf("%s%c", array[i].last_name, &endline) || endline != '\n') {
            return_case = 1;
            break;
        }
        if (!scanf("%d%c", &array[i].semester_grade, &endline) ||
        array[i].semester_grade < 0 || endline != '\n') {
            return_case = 1;
            break;
        }
    }
    return return_case;
}

int input_number_of_students() {
    int number;
    char endline;
    if (!scanf("%d%c", &number, &endline) || endline != '\n') {
        number = -1;
    }
    return number;
}

=====================================================================
/* Task 30 - Getting familiar with atoi			*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char char_numbers[3] = "123";
    int num_numbers = atoi(char_numbers);
    printf("%d\n", num_numbers * 3);
    printf("%s\n", char_numbers);
    return 0;
}

=====================================================================
/* Task 31 - Input multiply odd*/

#include <stdio.h>

int main() {
    int number = 0;
    int counter = 0;
    int array[5];
    while(counter != 5) {
        scanf("%d", &number);
        array[counter] = number;
        counter++;
    }
    int result_to_return = array[0];
    if (counter == 2) {
        printf("0");
    } 
    else if (counter == 1) {
        printf("%d", array[0]);
    } else {
        for (int i = 0; i < counter; i++) {
            if (i % 2 == 0) {
                printf("i isn't even %d\n", array[i]);
                result_to_return *= array[i];
            }
        }
    }
    printf("result - %d\n", result_to_return);
    return 0;
}

ввод не ограничен количеством целых чисел
на вывод: произведение нечетных чисел, если всего 2 числа  - выводить ноль, если одно число - вывести его (но положительным)

=====================================================================
/* Task 32 - Multiply every number by n-1 - Reworked with dynamic memory.c	*/
	
Дана последовательность целых чиселЧисло nСимвол конца -1
Вывести x1 xn x2 xn-1 x3 xn-2 и так далее

#include <stdio.h>
#include <stdlib.h>

int main() {
    int kArrayLenght = 2, counter_for_output, temp, *pointer_to_the_array;
    pointer_to_the_array = (int*)malloc(sizeof(int));
    if (pointer_to_the_array == NULL) {
        printf("n/a");
        return 1;
    } else {
        for (int i = 0; i < kArrayLenght; i++) {
            if (!scanf("%d", &temp)) {
                printf("n/a");
                return 1;
            } else if (temp == -1) {
                kArrayLenght = i;
            } else {
                pointer_to_the_array[i] = temp;
                kArrayLenght += 1;
                pointer_to_the_array = (int*)realloc(pointer_to_the_array, (kArrayLenght)*sizeof(int));
                }
        }
        counter_for_output = kArrayLenght;
        printf("Array of numbers after input:\n");
        for (int i = 0; i < kArrayLenght; i++) {
            printf("%d", pointer_to_the_array[i]);
            if (i < kArrayLenght - 1) {
                printf(" ");
            } else if (i == kArrayLenght - 1) {
                printf("\n");
            }
        }
        printf("Array of numbers multiplied:\n");
        for (int j = 0; j < kArrayLenght; j++) {
            printf("%d", pointer_to_the_array[j] * counter_for_output);
            counter_for_output--;
            if (j < kArrayLenght - 1) {
                printf(" ");
            }
        }
    }
    free(pointer_to_the_array);
}

=====================================================================
/* Task 33- Неограниченный ввод целых чисел. Записать в обратном порядке введенные числа. The last symbol is newline.*/ 

+ 1. Use malloc to allocate memory for the array of numbers
+ 2. Take input
+ 3. Use realloc to add more memory as I get more numbers
+ 4. Work around invalid input
+ 5. Test
+ 6. Cpplint test
+ 7. Add and push


#include <stdio.h>
#include <stdlib.h>

int main() {
    int realloc_counter = 1, *pointer_array_of_numbers, index_array = 0;
    pointer_array_of_numbers = (int*)malloc(realloc_counter * sizeof(int));

    if (pointer_array_of_numbers == NULL) {
        printf("Error - memory wasn't allocated");
        return 1;
    }

    char endline = ' ';

    while (endline != '\n') {
        if (scanf("%d%c", &pointer_array_of_numbers[index_array], &endline) &&
        ((endline == ' ') || (endline == '\n'))) {
            realloc_counter++;
            index_array++;
            pointer_array_of_numbers = (int*)realloc(pointer_array_of_numbers, realloc_counter * sizeof(int));
        } else {
            printf("n/a");
            free(pointer_array_of_numbers);
            pointer_array_of_numbers = NULL;
            return 1;
        }
    }

    // Output array in reverse
    for (int i = index_array - 1; i >= 0; i--) {
        printf("%d", pointer_array_of_numbers[i]);
        if (i != 0) {
            printf(" ");
        }
    }

    free(pointer_array_of_numbers);
    pointer_array_of_numbers = NULL;
    return 0;
}

=====================================================================
/* Task 34 - Transposition of any matrix			*/

#include <stdio.h>

int main() {
    int x, y;
    if (scanf("%d%d", &y, &x) == 2 && y > 0 && x > 0) {
        int my_matrix[y][x];
        int bad = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (scanf("%d", &my_matrix[j][i]) != 1)
                    bad = 1;
                if (bad)
                    break;
            }
            if (bad)
                break;
        }
        if (!bad) {
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    printf("%d", my_matrix[i][j] * my_matrix[i][j]);
                    if (j < x - 1) {
                        printf(" ");
                    }
                }
                if (i < y - 1)
                    printf("\n");
            }
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
}

   ===============================================================================
/* Task 35 - I'm Groot.  						lvl 1. 

Вывести на экран сообщение        "I'm Grood", (c) Grood  
Обратте внимание что должно быть выведено сообщение именно в таком формате с кавычками
На вход программы ничего не подается
--------------------------------------------------------------------------------*/

#include <stdio.h>
int main() {

    printf("\"I'm Grood\", (c) Grood"); 
    /* если поставить / перед  спец. символом, то он считывается как обычный символ, 
    это называется экранированием */
    return 0;
	
}

===============================================================================
/* Task 36 - Return five numbers  					lvl 1   
   
Дан шаблон программы, измените программу, чтобы она
считала на вход число и вывести его в формате ниже
Вход    Выход
0       00000
1       00001           
10      00010
666666  666666
--------------------------------------------------------------------------------*/
	   
	   
#include <stdio.h>
int main() {
    int num;
    scanf("%d", &num);
    printf("%05d", num);

    return 0;
}

  ===============================================================================
/* Task 37 - Radian calculating					lvl 2    

перевести радианы (действительное число) в градусы (целое число)
(проверка на то, что радианы >=0 НЕ НУЖНА, проверено мистейком)
Математически округлить ответ до двух знаков после запятой 
Дано 1 градус  = 57.29 рад

Пример
Вход Выход
1     57
2     115
--------------------------------------------------------------------------------*/	

	 
#include <stdio.h>
int main() {
    
    int degree;
    float radian = 57.29;
    scanf("%d", &degree); 
    printf("%.f", degree * radian);
    
    return 0;

}
  ===============================================================================
/* Task 38 - Задача с  FILE				  

Написать программу, осуществляющую подсчет количества цифр (0-9), которые содержатся в текстовом файле, путь которого задается на стандартном потоке ввода
(относительно кореновой директории), заканчивающеся символом новой строки \n.  Текст может содержать буквы латинского алфавита в верхнем и нижнем регистре, а также цифры (0-9) нижнего регистра.
(0-9) вывести на stdout без переноса строкию Проверить валидность. Ошибка "n/a". Путь к файлу всегда верный, и файл существует.
--------------------------------------------------------------------------------*/	

	 



=====================================================================


=====================================================================
/* Task 38 - Ссылки на сайт с задачами*/
https://studassistent.ru/c

=========================================== На сортировку ==================================================================

#include <stdio.h>
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
======
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

=====
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

=====
	
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

====
	
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
====
	
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
// Удалить последнее вхождение подстроки в строке

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200
                                                                     
void reverse_string(char *);
char *sub_string(char *, char *);

int main() {
    char string[N], substr[N];
    char *result;
    char c;
    int i = 0;

    while (scanf("%c", &c) == 1) {
        if (c == '\n') {
            string[i] = '\0';
            break;
        }
        string[i++] = c;
    }
    i = 0;
    while (scanf("%c", &c) == 1) {
        if (c == '\n') {
            substr[i] = '\0';
            break;
        }
        substr[i++] = c;
    }

    reverse_string(string);
    reverse_string(substr);

    result = sub_string(string, substr);

    printf("%s", result);
    return 0;
}

char *sub_string(char *string, char *substr) {
    int i = 0, j = 0, k = 0, n = 0, flag = 0;
    char *res = string;
    for (i = 0; res[i] != '\0'; i++) {
        k = i;
        if (!flag) {
            while (res[i] == substr[j]) {
                i++, j++;
                if (j == (int)strlen(substr)) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            i = k;
            j = 0;
        } else if (flag == 1) {
            res[n++] = res[i];
            continue;
        } else {
            flag = 0;
        }
        res[n++] = res[i];
    }
    res[n] = '\0';
    reverse_string(res);
    return res;
}

void reverse_string(char *str) {
    if (str == 0) {
        return;
    }
    if (*str == 0) {
        return;
    }

    char *start = str;
    char *end = start + strlen(str) - 1;
    char temp;

    while (end > start) {
        temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }
}




// Дано целое число, вывести максимальную его цифру

#include <stdio.h>
int max_digit(int number);  // Не ленитесь выносить логические куски кода в функции, их проще отлаживать, чем огромный main.

int main(void) {
  int number;

  if (scanf("%d", &number) != 1) {  // Задачу не встречал - не знаю нужна ли здесь проверка на n/a или проверка на отрицательное число.
    printf("n/a");
  } else {
    printf("%d", max_digit(number));
  }

  return 0;
}

int max_digit(int number) {
  int max_digit = 0;  // Давайте переменным осмысленные названия - код и отладка проще восприниматься будет.

  if (number < 0) {  // Если в условии число может быть отрицательным, то нам удобнее его сделть положительным.
    number *= -1;
  }

  while (number) {  // Пока number != 0. Если number изначально равен нулю, то у нас уже max_digit = 0 выше.
    int digit = number % 10;  // Получаем число единиц в числе, то есть правую цифру. 123 % 10 = 3;

    if (digit > max_digit) {  // Обновляем ответ (наибольшую цифру).
      max_digit = digit;
    }

    number /= 10;  // Получаем число десятков в числе, то есть число без последней цифры. 123 / 10 = 12;
  }

  return max_digit;
}



// Найти максимальное число из непустой последовательности неотрицательных чисел, кончающейся на -1.
#include <stdio.h>

int main(void) {
  int number = 0;
  int max_value = -1;

  while (number != -1) {
    scanf("%d", &number);
    if (number > max_value) {
      max_value = number;
    }
  }

  printf("%d", max_value);

  return 0;
}


Задания для решений: 
5 - вывести матрицу с числами от 1 до н^2 по змейке из левого верхнего угла в центр (как на степике)
4 - повернуть матрицу на 90 градусов по часовой стрелке 
3 - вывести массив неопределенной длины (ввод заканчивается на -1) задом наперед 
2 - перевести радианы (действительное число) в градусы (целое число)
1 - вывести строчку, где внутри есть " и '

3 - поменять Макс и мин в массиве, заканчивающемся на -1

1. Исправить программу, там чёт простое, типа int pi = 3.14 было
2. Перевести из радианов в градусы (проверка на то, что радианы >=0 НЕ НУЖНА, проверено мистейком)
3. Дано целое число, вывести максимальную его цифру  // решена
4. Есть матрица, надо поменять местам строки, содержащие первые вхождения максимального и минимального элементов матрицы
5. На вход подаётся положительное число, надо вывести матрицу, заполненную числами от 1 до n^2 по спирали, типа
1 2 3
8 9 4
7 6 5

*/
