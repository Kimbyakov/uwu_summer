// определить является ли введенное слово палиндромом

#include <stdio.h>

int main(){

    char word[200];
    int len = 0;
    int flag = 0;

    while (scanf("%c", &word[len]) == 1 && word[len] != '\n') {
        if (word[len] >= 'a' && word[len] <= 'z')
            word[len] -= 32;
        len++;
    }

    
    for (int i = 0; i < len; i++){
        if (word[i] != word[len-i-1]){
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
