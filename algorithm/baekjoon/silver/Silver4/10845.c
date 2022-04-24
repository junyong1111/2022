#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100000

typedef struct {
    int data[SIZE];
    int front;
    int rear;
}QueueType;

void init(QueueType *Q)
{
    Q->front = 0;
    Q->rear = -1;
}

int empty(QueueType *Q)
{
    return Q->rear < Q->front;
}

void push(QueueType *Q, int elem){
    Q->data[++Q->rear] = elem;
}

int pop (QueueType *Q){
    if(empty(Q)){
        return -1;
    }
    else{
        return Q->data[Q->front++];
    }
}

void size(QueueType *Q){
    printf("%d\n", (Q->rear+1)- (Q->front));
}

int front(QueueType *Q){
    if(empty(Q)){return -1;}
    return Q->data[Q->front];
}

int back(QueueType *Q){
    if(empty(Q)){return -1;}
    return Q->data[Q->rear];
}

int main(void){
    char *Push = "push";
    char *Pop = "pop";
    char *Size = "size";
    char *Empty = "empty";
    char *Front = "front";
    char *Back = "back";
    QueueType Q;
    init(&Q);
    int N = 0;
    scanf("%d", &N);
    

    for(int i=0; i<N; i++){
        
        char str[100];
        scanf("%s", str);
        if(strcmp(Push, str)==0){
            int num = 0;
            scanf("%d", &num);
            push(&Q,num);
        }

        else if(!strcmp(Pop, str))
            printf("%d\n", pop(&Q));
        
        else if(!strcmp(Size, str))
            size(&Q);
    
        else if(!strcmp(Empty, str))
            printf("%d\n", empty(&Q));
        
        else if(!strcmp(Front, str))
            printf("%d\n", front(&Q));
    
        else 
            printf("%d\n", back(&Q));     
    }
    
    return 0;
}