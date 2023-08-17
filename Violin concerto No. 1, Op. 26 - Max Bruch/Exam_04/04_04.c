// Задача 04_04 (Наибольшая цифра):

#include <stdio.h>

int main(void) {

    int n, maximum = 0;
    char end;

    if (scanf("%d%c", &n, &end) == 2 && (end == '\n' || end == EOF)) {
    	
    	if (n < 0) {
    		n = -n;
    	}

	    while (n > 0) {
	        if (n % 10 > maximum) {
	        	maximum = n % 10;
	        }
	        n = n / 10;
	    }

	    printf("%d", maximum);

    } else {
		printf("n/a");
	}
	
    return 0;
}
