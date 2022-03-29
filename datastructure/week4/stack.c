#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct
{
    char data[SIZE];
    int top;
}StackType;

void init(StackType * S)
{   
    S->top = -1; //배열이 아닌 배열의 밖을 지정해주는 행위
}

int isEmpty(StackType * S)
{
    return S->top == -1; //비었는지 안 비었는지 리턴
}

int isFull(StackType * S)
{
    return S->top == SIZE-1; // 꽉 차있는지 
}

void push(StackType * S, char elem)
{
    if(isFull(S))
        printf("Overflow!!\n");
     // 여기서는 주소연산자를 사용 안함 이미 주소를 받았기 때문에
    else
        S->top++;
        S->data[S->top] = elem;
    
}

char pop(StackType * S)
{
    if(isEmpty(S))
       { printf("Empty!!\n");
        return -1;
       }
    char elem = S->data[S->top];
    S->top--;
    return elem;
} //값을 리턴하고 제거

char peek(StackType * S)
{
    if(isEmpty(S))
       { printf("Empty!!\n");
        return -1;
       }
    return S->data[S->top];
} //값만 리턴

void print(StackType * S)
{
    for(int i=0; i<=S->top; i++){
        printf("%c ", S->data[i]);
    }
    printf("\n");
}


int main(void){
    StackType S;
    init(&S);

    pop(&S); getchar(); // 오류를 체크하기 위해
    push(&S, 'c');
    push(&S, 'a');
    push(&S, 't');
    push(&S, 's');
    print(&S); getchar();

    printf("Call pop() : %c\n", pop(&S)); print(&S); getchar();
    printf("Call peek() : %c\n", peek(&S)); print(&S); getchar();
    return 0;
}