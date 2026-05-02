#include <stdio.h>


// EXERCISE 1
int custom_strlen(char str[]){
    int length = 0;
    
    while (str[length] != "\n"){
        length++;
    }

    return length;
}

void exercise_1(){
    char myString[] = "Hello World";

    int len = custom_strlen(myString);
    printf("Duljinata na niza e: %d\n", len);

}

// EXERCISE 2
int count_words(char *str){
    int count = 0;
    int inWord = 0;

    while (*str){
        if (*str == " " || *str == "\n" || *str == "\t"){
            inWord = 0;
        } else if (inWord == 0){
            inWord = 1;
            count++;
        }
        str++;
    }
    return count;
}

void exercise_2(){
    char text[] = "It is an example for counting words.";
    printf("Counting words: %d\n", count_words(text));
}

// EXERCISE 3
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

void exercise_3(){
    char text[] = "Hello World";
    count_letters(text); 
}

// EXERCISE 4
int custom_strcmp(char *s1, char *s2){
    while (*s1 && (*s1 == *s2)){
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

void exercise_4(){
    char str1[] = "Apple";
    char str2[] = "Apple";

    if(custom_strcmp(str1, str2) == 0){
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }
}

// EXERCISE 5
int count_vowels(char *str){
    int count = 0;
    while (*str){
        char c = *str;
        if(c == "a" || c == "e" || c == "i" || c == "o" || c == "u" ||
           c == "A" || c == "E" || c == "I" || c == "O" || c == "U"){
            count++;
        }
        str++;
    }
    return count;
}

void exercise_5(){
    char text[] = "Hello World";
    printf("Number of vowels: %d\n", count_vowels(text));
    
}

// EXERCISE 6
void to_uppercase(char *str){
    while (*str){
        if(*str >= "a" && *str <= "z"){
            *str -= 32;
        }
        str++;
    }
}

void exercise_6(){
    char text[] = "Hello World 123";
    to_uppercase(text);
    printf("Result: %s\n", text);

}


int main(){
    int choice;

    while (1) {
        printf("\n==========================\n");
        printf("       SELECT A TASK      \n");
        printf("==========================\n");
        printf("1-6: Run Exercise\n");
        printf("Note: Number 4 is bonus exercise");
        printf("0:    Exit Program\n");
        printf("--------------------------\n");
        printf("Your choice: ");

        if (scanf("%d", &choice) != 1){
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        if (choice == 0){
            printf("Exiting... Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: exercise_1(); break;
            case 2: exercise_2(); break;
            case 3: exercise_3(); break;
            case 4: exercise_4(); break;
            case 5: exercise_5(); break;
            case 6: exercise_6(); break;
            default: printf("No such task! Try again.\n");
        }
    }

    return 0;
}