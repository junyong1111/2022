#include <stdio.h>
#include <stdlib.h>

typedef struct Stacknode{
    char data;
    struct Stacknode* next;
}Stacknode;

typedef struct {
    Stacknode * top;
}StackType;

void init(StackType *S){
    S->top = NULL;
}

void push(StackType *S ,char elem){
    Stacknode * node = (Stacknode*)malloc(sizeof(Stacknode));
    node->data = elem;
    node->next = S->top;
    S->top = node;
}

int isEmpty(StackType *S){
    return S->top == NULL;
}

char pop(StackType *S){
    if(isEmpty(S)){
        printf("STACK IS EMPTY\n");
        return'E';
    }
    
    else{
        Stacknode *P = S->top;
        char temp = P->data;
        S->top = P->next;
        free(P);
        return temp;
    }
}

char peek(StackType *S){
     if(isEmpty(S)){
        printf("STACK IS EMPTY\n");
        return'E';
    }
      else{
        return S->top->data;
    }
}

void print(StackType * S){
    for(Stacknode *P = S->top; P!=NULL; P=P->next){
        printf("%c ->",P->data);
    }
    printf("\b\b \n");
}









int main(){

    StackType S;
    init(&S);
    push(&S, 'A');
    push(&S, 'B');
    push(&S, 'C');
    push(&S, 'D');
    print(&S);
    getchar();
    pop(&S);
    pop(&S);
    pop(&S);
    print(&S);
    printf("%c\n",peek(&S));


    return 0;
}