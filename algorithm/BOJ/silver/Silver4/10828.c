#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100000

typedef struct Stack{
    int data[SIZE];
    int top;
}Stack; //Stack 정의

void init(Stack *S){
    S->top = -1;
}  // 시작 시 스택의 화살표를 -1로

int full(Stack *S){
    return S->top==(SIZE-1);
} //스택이 꽉 찼는지 확인

int empty(Stack *S){
    return S->top==-1;
} //스택이 비었는지 확인

void push(Stack *S, int elem)
{
    if(full(S)){
    }
    else{
        S->top ++;
        S->data[S->top] = elem; 
    }
} //꽉 차있는지를 확인 후 원하는 값 삽입

int pop(Stack *S){
    if(empty(S)){
        return -1;
    }
    else{
        int temp = S->data[S->top];
        S->top--;
        return temp;
    }
} //비어있는지 확인 후 스택의 맨 마지막을 제거 후 리턴

int size(Stack *S){
    return S->top+1;
} //스택의 사이즈를 리턴

int top(Stack *S){
    if(empty(S)){
        return -1;
    }
    else{
        return S->data[S->top];
    }
} //스택의 맨 마지막 값만을 리턴 제거X

int main(){
    int N ;
    int elem = 0;
    int len =0;
    char str[100];
    char *check = "push";
    char *check1 = "pop";
    char *check2 = "size";
    char *check3 = "empty";
    char *check4 = "top";
    scanf("%d", &N);
    Stack S;
    init(&S);
    for(int i=0; i<N; i++){
        scanf("%s",str);

        if(!strcmp(str, check)) // 같으면 0
        {
            scanf("%d", &elem);
            push(&S,elem);
        }
        else if(!strcmp(str, check1)) 
        {
            printf("%d\n",pop(&S));
        }

        else if(!strcmp(str, check2)){
            printf("%d\n",size(&S));
        }

        else if(!strcmp(str, check3)){
            printf("%d\n",empty(&S));
        }
        else if(!strcmp(str, check4)){
            printf("%d\n",top(&S));
        }

     }
    return 0;
}