#include <stdio.h>
#include <stdlib.h>

int main(){
    int count = 0, i;
    int *stations = NULL, *ptrToStations = NULL;

    for(i = 1; i <= 7; i++, count++)
        ptrToStations = (int*) realloc(stations, count * sizeof(int));
    if(ptrToStations != NULL){
        stations = ptrToStations;
        stations[count] = i;
    }

    for(i = 0; i < 7; i++)
        printf("%d\n", stations[i]);
    printf("\n");

    // Adding an 8th element
    ptrToStations = (int*) realloc(stations, ++count * sizeof(int));
    
    if(ptrToStations != NULL){
        stations = ptrToStations;
        stations[count-1] = count;
    }

    for(i = 0; i < count; i++)
        printf("%d\n", stations[i]);
    printf("\n");

    if (stations != NULL){
        free(stations);
    }

    return 0;
}