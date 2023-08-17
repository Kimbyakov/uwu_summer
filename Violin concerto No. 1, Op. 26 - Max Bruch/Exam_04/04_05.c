// Задача 04_05 (Product of odd digits):

#include <stdio.h>

int main(void) {

 	int n, product = 1, counter = 0;
    char end;

    if (scanf("%d%c", &n, &end) == 2 && (end == '\n' || end == EOF)) {
    	
    	if (n < 0) {
    		n = -n;
    	}

	    while (n > 0) {
	        
	        if (n % 10 % 2 != 0) {
	            product *= n % 10;
	            counter++;
	        }

	        n = n / 10;        
	    }

	    if (counter > 0) {
	    	printf("%d", product);
	    } else {
	    	printf("0");
	    }

    } else {
		printf("n/a");
	}
	
    return 0;
}
