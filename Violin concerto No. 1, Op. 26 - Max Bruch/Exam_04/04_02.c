// Задача 04_02 (Поиск наибольшего):

#include <stdio.h>

int main(void) {

    int n, maximum = 0, flag = 1;

    while (n != -1) {
        if (scanf("%d", &n) == 1 && n >= -1) {
	        if (n > maximum) {
	            maximum = n;
	        }
	    } else {
	    	flag = 0; // False
	    	break;
	    }
	}

	if (flag == 1) {
		printf("%d", maximum);
	} else {
		printf("n/a");
	}
	
    return 0;
}
