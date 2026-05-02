#include <stdio.h>

int count_vowels(char *str){
    int count = 0;
    while (*str){
        char c = *str;
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            count++;
        }
        str++;
    }
    return count;
}

int main(){
    char text[] = "Hello World";
    printf("Number of vowels: %d\n", count_vowels(text));
    
    return 0;
}