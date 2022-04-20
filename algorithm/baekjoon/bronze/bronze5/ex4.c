// 백준(8393) 합

#include <stdio.h>

int main(void){
    int n ;
    scanf("%d", &n);
    int Sum = 0; // 1부터 n까지의 합을 저장할 Sum변수 선언
    for(int i=0; i<=n; i++){
        Sum = Sum+i; 
        //for문을 돌면서 1부터 n까지의 합을 Sum의 저장
    }
    printf("%d\n",Sum);
    return 0;
}