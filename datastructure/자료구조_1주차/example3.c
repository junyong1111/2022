// 예제_3: 자릿수 출력
#include <stdio.h>

int main(void){
    int N ;
    scanf("%d", &N); // 정수 입력
    while(N!=0){ // 정수값이 0보다 큰 경우
        printf("%d\n", N%10); 
        N = N/10; 
    } // while

    return 0;
}