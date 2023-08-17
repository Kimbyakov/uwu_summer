// Задача 05_01 (Скалярное произведение):

#include <stdio.h>
#include <stdlib.h>

int getNumbers(int *number, int n);

int main() {
	
   	int n;
  	scanf("%d", &n);
                           
  	int *A = (int*)malloc(n * sizeof(int));            // создаем первый динамический массив
  	int *B = (int*)malloc(n * sizeof(int));            // создаем второй динамический массив

  	if (A != NULL && B != NULL) {                      // если память выделилась:

  		if (getNumbers(A, n) && getNumbers(B, n)) {    // если ввод верный

		  	int result = 0;

		    for (int i = 0; i < n; i++) {
		      	result += A[i] * B[i];
		    }

		  	printf("%d", result);
	
	 	} else {                                       // если ввод неверный
  			printf("n/a");
  		}

  		free(A);
	  	free(B);
    	
  	} else {                                           // если память не выделилась
  		printf("n/a");
  	}

  	return 0;
}

int getNumbers(int *number, int n) {
  	char end;
  	int flag = 1;   
  	                                 // ожидаем адекватный вход
  	for (int i = 0; i < n; i++) {
    	if (scanf("%d%c", &number[i], &end) == 2) {
    		if (i != n - 1) {
    			if (end != ' ') {
    				flag = 0;                        // False - ошибка ввода
    				break;
    			}
    		} else {
				if (end != '\n' && end != EOF) {
    				flag = 0;                        // False - ошибка ввода
    				break;
    			}
    		}
    	} else {
    		flag = 0;                                // False - ошибка ввода
    		break;
    	}
  	}

  	return flag;
}
