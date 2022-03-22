// 예제_1 : 가격계산
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int K , N ,M ; 
    // K(가격), N(햄버거 개수), M(지갑에 있는 돈)
    scanf("%d %d %d", &K, &N, &M);
    // 각각의 값을 scanf함수로 받음
    int total = K*N;
    //총 햄버거의 가격
    if (total > M){
        printf("%d\n" ,total -M);
        // 가격이 부족한 경우
    }
    else {
        printf("0\n");
    }
    return 0;
}