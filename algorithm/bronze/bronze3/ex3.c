//백준(2440) 별찍기 -3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
    int N = 0;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i+j <N)
                printf("*");
            else
                continue;
        }
        printf("\n");
    }
    return 0;
}