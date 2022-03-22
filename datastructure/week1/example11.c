// 예제_11: 구조체 응용
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int account;
    int balance;
    int name[20];
}Bank; //구조체

void deposit(Bank *a, int amount)
{
    //(*a).balance += amount ;
    a->balance += amount ;
    printf("%d %s : %d\n", a->account, a->name, a->balance);
}

int main(){

    Bank a;
    scanf("%d %s %d", &a.account, a.name, &a.balance);
    printf("%d %s: %d\n", a.account, a.name, a.balance);

    deposit(&a, 10000);
    printf("%d %s: %d\n", a.account, a.name, a.balance);
    //구조체 변수는 레퍼런스를 가지고 있지않다. 클래스 객체와 구조체와의 차이이다. 즉 , 인자로 a를 주면 call by value , 인자로 &a를 주면 call by reference이다 

    return 0;    
}
//Main함수에는 구조체를 접근할 때 .으로 접근하지만 사용자 정의 함수에서는 구조체 주소와 ->를 쓴다.