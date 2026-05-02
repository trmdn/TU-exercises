#include <stdio.h>

void count_letters(char *str){
    int freq[256] = {0};

    while (*str){
        freq[*str]++;
        str++;
    }

    printf("Chestota na bukvite:\n");
    for (int i = 0; i < 256; i++){
        if (freq[i] > 0 && ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))){
            printf("%c: %d\n", i, freq[i]);
        }
    }
}

int main(){
    char text[] = "Hello World";
    printf("Hello World\n");
    count_letters(text);

    return 0;
}