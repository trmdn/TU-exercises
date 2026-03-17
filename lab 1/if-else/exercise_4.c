#include <stdio.h>

int main() {
    int digit;
    printf("Въведи цифра (0-9): ");
    scanf("%d", &digit);
    printf("Името на цифрата е: ");
    switch (digit)
    {
    case 0: printf("нула\n"); break;
    case 1: printf("едно\n"); break;
    case 2: printf("две\n"); break;
    case 3: printf("три\n"); break;
    case 4: printf("четири\n"); break;
    case 5: printf("пет\n"); break;
    case 6: printf("шест\n"); break;
    case 7: printf("седем\n"); break;
    case 8: printf("осем\n"); break;
    case 9: printf("девет\n"); break;
    
    default: printf("Това не е цифра!");
    }

    return 0;
}