#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 51

int main(){
    FILE *txtFile = fopen("input.txt", "r");
    if(!txtFile){
        printf("Greshka pri otvarqne na input.txt\n");
        return 1;
    }

    char **selectedWords = NULL;
    int count = 0;
    char currentWord[MAX_WORD_LEN];
    char lastChar = '\0';

    while (fscanf(txtFile, "%s", currentWord) == 1){
        if (count == 0 || currentWord[0] == lastChar){
            selectedWords = (char **)realloc(selectedWords, (count + 1) * sizeof(char *));
            selectedWords[count] = malloc(strlen(currentWord) + 1);
            strcpy(selectedWords[count], currentWord);

            lastChar = currentWord[strlen(currentWord) - 1];
            count++;
        }
    }
    fclose(txtFile);

    FILE *binFileOut = fopen("output.bin", "wb");
    if (!binFileOut){
        printf("Greshka pri suzdavane na binarniq file!\n");
        return 1;
    }

    for (int i = 0; i < count; i++){
        fwrite(selectedWords[i], sizeof(char), strlen(selectedWords[i]), binFileOut);
        if (i < count - 1){
            char space = ' ';
            fwrite(&space, sizeof(char), 1, binFileOut);
        }
        free(selectedWords[i]);
    }
    free(selectedWords);
    fclose(binFileOut);


    printf("Sudurjanie na binarniq file:\n");
    FILE *binFileIn = fopen("output.bin", "rb");
    if(!binFileIn) return 1;

    char ch;
    while (fread(&ch, sizeof(char), 1, binFileIn) == 1){
        printf("%c", ch);
    }
    printf("\n");
    fclose(binFileIn);

    return 0;
}