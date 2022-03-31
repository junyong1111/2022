#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



int evaluate(char exp[])
{
    StackType S;
    init(&S);
    int first , second, value;
    char c;
    int n = strlen(exp);

    for(int i=0; i<n; i++){
        c = exp[i];
        if( c!= '+' && c!= '-' && c!= '*' && c!= '/'){
            value =  c - '0';
            push(&S, value);
        }
        else{
            second = pop(&S);
            first = pop(&S);

            switch(c)
            {
                case '+':
                    push(&S, first + second);
                    break;
                case '-':
                    push(&S, first - second);
                    break;
                case '*':
                    push(&S, first * second);
                        break;
                case '/':
                    push(&S, first / second);
                        break;
            } //S-W 
        }  //else 
    }//for
    return pop(&S);
}

int prec(char op){

    switch(op){
        case '(' : case ')':
            return 0;
        case '+' : case '-':
            return 1;
        case '*' : case '/':
            return 2;
    }
}

void convert(char exp[])
{
    StackType S;
    init(&S);
    char c, t;
    int len = strlen(exp);

    for(int i=0; i<len; i++){
        c = exp[i];
        
        switch (c)
        {
        case '+': case '-': case '*': case '/':
            while(!isEmpty(&S) && prec(c) <= prec(peek(&S))){
                printf("%c", pop(&S));
            }
            push(&S, c);
            break;

        case '(':
            push(&S, c);
            break;

        case ')':
            t = pop(&S);
            while(t!= '(')
            {
                printf("%c", t);
                t = pop(&S);
            }
            break;
        default :
            printf("%c", c);
            break;
       
        } // S-W

    }//for

    while(!isEmpty(&S))
        printf("%c", pop(&S));
    printf("\n");
}

int main(void)
{
    char exp[SIZE];
    scanf("%s", exp);
    convert(exp);
    
    
    
    return 0;
}