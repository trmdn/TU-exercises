#include <stdio.h>

int main() {
    int day;
    printf("Въведи число за ден от седмицата (1-7): ");
    scanf("%d", &day);

    switch (day) {
    case 1: printf("Понеделник\n"); break;
    case 2: printf("Вторник\n"); break;
    case 3: printf("Сряда\n"); break;
    case 4: printf("Четвъртък\n"); break;
    case 5: printf("Петък\n"); break;
    case 6: printf("Събота\n"); break;
    case 7: printf("Неделя\n"); break;
    default: printf("Невалидно число! Въведи число от 1 до 7"); break;
    }
    return 0;
}