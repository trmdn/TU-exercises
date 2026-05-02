#include <stdio.h>

int custom_strcmp(char *s1, char *s2){
    while (*s1 && (*s1 == *s2)){
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int main(){
    char str1[] = "Apple";
    char str2[] = "Apple";
    printf("Apple\n");
    printf("Apple\n");


    if(custom_strcmp(str1, str2) == 0){
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }


    return 0;
}