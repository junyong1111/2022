// 예제_4 : 정수를 입력받아 1~N까지 홀수와 짝수의 합 구하기
#include <stdio.h>

int main(void){
    int N; 
    scanf("%d", &N); //정수 입력
    int evenSum = 0; // 짝수 합 
    int oddSum = 0; // 홀수 합
    // 합은 0으로 초기화 시켜주는게 좋음

    for (int i=1; i<=N; i++){
        if (i%2 == 0) //짝수 조건
            evenSum = evenSum + i;
        else
            oddSum = oddSum +  i;
    }
    
    printf("%d\n%d\n",evenSum, oddSum);
    return 0;
}