//백준(2439) 별찍기
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N ;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i+j >= N-1){ //인덱스를 이용하여 접근
                printf("*");
            }
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}