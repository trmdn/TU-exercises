#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n;
    int * stations;
    i = 7;
    int *prtToStations;
    stations = (int*) calloc (i, sizeof(int));
    if (stations==NULL) exit (1);
    for (n=0; n<i; n++)
        stations[n] = n;
    for (n=0; n<i; n++)
        printf("%d\n", stations[n]);
    printf("\n");
    
    prtToStations = stations;

    stations = (int*) calloc (i++, sizeof(int));
    for(n = 0; n < 7; n++)
        stations[n] = prtToStations[n];
        stations[i-1] = i;
        
    for (n = 0; n < 7; n++)
        printf("%d\n", stations[n]);
    printf("\n");
    
    free(prtToStations);

    prtToStations = stations;
    int x = 3;

    for(n = x; n < i; n++)
        stations[n-1] = prtToStations[n];
    
    for(n = 0; n < 7; n++)
        stations[n] = prtToStations[n];
    
    for (n = 0; n < 7; n++)
        printf("%d\n", stations[n]);
    printf("\n");
    
    free(prtToStations);
    free(stations);
    
    return 0;
}