#include <stdio.h>

int count_words(char *str){
    int count = 0;
    int inWord = 0;

    while (*str){
        if (*str == ' ' || *str == '\n' || *str == '\t'){
            inWord = 0;
        } else if (inWord == 0){
            inWord = 1;
            count++;
        }
        str++;
    }
    return count;
}

int main(){
    char text[] = "It is an example for counting words.";
    printf("It is an example for counting words.\n");
    printf("Counting words: %d\n", count_words(text));
    return 0;
}