// 예제_10: 구조체를 사용하여 접근해보기
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int account;
    int balance;
    char name[20];
    // 정보 입력
} Bank; //구조체 별명

int main(){

    Bank a;
    scanf("%d %s %d", &a.account, a.name , &a.balance);
    printf("%d %s %d\n", a.account, a.name, a.balance);

    return 0;
}

