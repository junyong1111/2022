// 백준(1001) A-B

#include <stdio.h>

int main(void){
    int A,B;
    //두 개의 정수를 받을 A,B선언
    scanf("%d %d", &A, &B);
    //A,B입력
    int C = A - B; 
    //A-B 데이터를 받을 새로운 C변수 선언
    printf("%d\n", C); 
    return 0;
}
