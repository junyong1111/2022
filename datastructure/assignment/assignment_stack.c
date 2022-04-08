#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct 
{
    int point ;
    char data[MAX_SIZE];

}Stack;

void init(Stack * S){
    S->point = -1;
}

int isFull(Stack * S){
    return (S->point == MAX_SIZE-1); // 꽉 차 있다면 1을 반환
}

int isEmpty(Stack * S){
    return S->point == -1 ; //비어있다면 1을 반환
}

void push(Stack *S,  char elem){
    if(isFull(S))
        printf("Stack is Full\n");
    else{
        S->point ++;
        S->data[S->point] = elem;
    }
}

char pop(Stack *S){
    char temp;
    if(isEmpty(S))
        {   
            //printf("Stack is Empty\n");
            return -1;
        }

    else{
        temp = S->data[S->point];
        S->point --;
    }
    return temp;
}

char peek(Stack *S){
    char temp;
    if(isEmpty(S))
        {   
            //printf("Stack is Empty\n");
            return -1;
        }
        
    else{
        temp = S->data[S->point];
    }
    return temp;
}

void print(Stack* S)
{
    for(int i = 0; i < S->point; i++)
        printf("%c", S->data[i]);
    printf("\n");
}

int evaluate(char exp[]){
    Stack S;
    init(&S);

    int first = 0;
    int second = 0;
    int value = 0;
    char c ;
    int len = strlen(exp);

    for(int i=0; i<len; i++){
        c = exp[i];

        if(c!= '+' && c!= '-' && c!= '*' && c!= '/') //피연산자이면
        {
            value = c - '0'; // 글자 0의 아스키코드 49 따라서 문자를 숫자로 바꾸는 연산
            push(&S,value); 
        }

        else{
            second = pop(&S);
            first = pop(&S);
            switch(c){
                case '+' :
                    push(&S, first+second);
                    break;
                case  '-' :
                    push(&S, first-second);
                    break;
                case '*' :
                    push(&S, first*second);
                    break;
                case '/' :
                    push(&S, first/second);
                    break;
            }
        }

    }
    return pop(&S);
}



int prec(char op){
    switch(op){
        case '(' : case ')':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
    }
}

void convert(char infix[] , char postfix[]){
    Stack S;
    init(&S);

    char c, t;
    int idx = 0;
    int len = strlen(infix);
    
    for(int i=0; i<len; i++){

        c = infix[i];

        switch(c){
            case '+': case '-' : case '*' :case '/': //연산자의 경우 계속 팝
                while(!isEmpty(&S) && prec(c) <= prec(peek(&S)))
                    {
                        char temp = pop(&S);
                        postfix[idx++] = temp;
                        //printf("%c", pop(&S)); // 연산자를 다 빼고
                    
                    }
                push(&S, c); // 연산자 삽입
                break;
            case '(':
                push(&S, c); 
                break;

            case ')':
                t = pop(&S);
                while(t!= '('){
                    postfix[idx++] = t;
                   // printf("%c", t);
                    t = pop(&S);
                }
                break;
            default :
                postfix[idx++] = c;
                //printf("%c", c);
        }

    } //for

    while(!isEmpty(&S)){
        postfix[idx++] = pop(&S);
        //printf("%c", pop(&S));
    }
}


int main(){
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    scanf("%s", infix);
    convert(infix, postfix);
    /*
    for(int i=0; i< strlen(postfix); i++){
        printf("%c", postfix[i]);
    }
    printf("\n");
    */
   
    int result = evaluate(postfix);
    printf("%d\n", result);
    
    return 0;
}