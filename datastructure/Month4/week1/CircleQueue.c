#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct 
{
   char data[SIZE];
   int front, rear;
}QueueType;


void init(QueueType * Q){
    Q->front = 0;
    Q->rear = 0;
}//수정

int isEmpty(QueueType * Q){
    return Q->rear == Q->front;
} //front 와 rear가 만난경우

int isFull(QueueType * Q){
    return Q->front == (Q->rear+1) %SIZE;
}//수정

void enqueue(QueueType * Q, char elem){
    if (isFull(Q)){
        printf("Queue is Full!!\n");
        return;
    }
    Q->rear = (Q->rear+1) % SIZE;
    Q->data[Q->rear] = elem;
}//수정

char dequeue(QueueType * Q){
    if(isEmpty(Q)){
        printf("Queue is Empty!!!\n");
        return -1;
    }
    Q->front = (Q->front+1) % SIZE;
    return Q->data[Q->front];
}  //수정


char peek(QueueType * Q){
    if(isEmpty(Q)){
        printf("Queue is Empty!!!\n");
        return -1;
    }
    return Q->data[(Q->front+1)%SIZE];
}//수정

void print(QueueType * Q){
    printf("Front pos : %d, Rear pos : %d \n", Q->front, Q->rear);
    int i = Q->front ;
    while(i!=Q->rear){
        i = (i+1) % SIZE;
        printf("[%c] ", Q->data[i]);
    }
    printf("\n");
}//수정
int main(void){
    QueueType Q;
    init(&Q);
    srand(time(NULL));

    //rand()% 26 + 65 //65~91까지
    for(int i=0; i<7; i++)
        enqueue(&Q, rand()% 26 + 65 ); // 함수는 문자를 받기 때문에 정수를 변환해야 함
    
    print(&Q); getchar();

    for(int i=0; i<3; i++)
        printf("[%c] ", dequeue(&Q)); 
    

    printf("\n\n");
    print(&Q); getchar();

    for(int i=0; i<5; i++)
        enqueue(&Q, rand()% 26 + 65 ); // 함수는 문자를 받기 때문에 정수를 변환해야 함
    print(&Q); getchar();
    
    for(int i=0; i<3; i++)
        printf("[%c] ", dequeue(&Q)); 
    
    printf("\n\n");
    print(&Q); getchar();


    return 0;
}