#include <stdio.h>

#define MAX 100001

int friends_count[MAX];

int main(){
    int N, M;

    if(scanf("%d %d", &N, &M) != 2) return 0;

    for(int i = 0; i <= N; i++){
        friends_count[i] = 0;
    }

    for(int i = 0; i < M; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        if(a >= 1 && a <= N) friends_count[a]++;
        if(b >= 1 && b <= N) friends_count[b]++; 
    }

    int query_person;
    printf("Vuvedete nomer na chovek za spravka: ");
    if(scanf("%d", &query_person) == 1){
        if(query_person >= 1 && query_person <= N){
            printf("Chovekut %d ima %d priqteli", query_person, friends_count[query_person]);
        } else{
            printf("Nevaliden nomer na chovek");
        }
    }

    return 0;
}