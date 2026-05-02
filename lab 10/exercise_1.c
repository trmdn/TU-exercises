#include <stdio.h>

int custom_strlen(char str[]){
    int length = 0;
    
    while (str[length] != '\0'){
        length++;
    }

    return length;
}

int main(){
    char myString[] = "Hello World";

    int len = custom_strlen(myString);
    printf("Hello World\n");
    printf("Duljinata na niza e: %d\n", len);

    return 0;
}