#include <stdio.h>

void to_uppercase(char *str){
    while (*str){
        if(*str >= 'a' && *str <= 'z'){
            *str -= 32;
        }
        str++;
    }
}

int main(){
    char text[] = "Hello World 123";
    to_uppercase(text);
    printf("Result: %s\n", text);

    return 0;
}