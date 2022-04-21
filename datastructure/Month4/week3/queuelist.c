#include <stdio.h>
#include <stdlib.h>

typedef struct Queuenode{
    char data;
    struct Queuenode* next;
}Queuenode;

typedef struct {
    Queuenode * front;
    Queuenode * rear;
}QueueType;

void init(QueueType *Q){
    Q->front = NULL; 
    Q->rear = NULL;
}

int insEmpty(QueueType *Q){
    return Q->front == NULL;
}

void enqueue(QueueType *Q , char elem)
{
    Queuenode* node = (Queuenode*)malloc(sizeof(Queuenode));
    node->data = elem;
    node->next = NULL;

    if(insEmpty(Q))
        Q->front = Q->rear = node;
    else{
        Q->rear->next = node;
        Q->rear = node;
    }
}

char dequeue(QueueType *Q){
    Queuenode *P = Q->front;
    char temp = P->data;
    Q->front =P->next;
    if(Q->front == NULL)
        Q->rear = NULL;
    free(P);
    return temp;
}


void print(QueueType *Q){
    Queuenode *P = Q->front;

    for(; P!=NULL; P=P->next){
        printf("%c => ", P->data);
    }
    printf("\n");
}

int main(){

    QueueType Q;
    init(&Q);
    enqueue(&Q , 'A'); print(&Q);
    enqueue(&Q , 'B'); print(&Q);
    enqueue(&Q , 'C'); print(&Q);
    enqueue(&Q , 'D'); print(&Q);
    printf("deleted -> %c\n",dequeue(&Q));
    printf("deleted -> %c\n",dequeue(&Q));
    print(&Q);
    


    return 0;
}