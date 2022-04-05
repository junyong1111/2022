#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

typedef struct 
{
   char data[SIZE];
   int front, rear;
    /* data */
}QueueType;


void init(QueueType * Q){
    Q->front = -1;
    Q->rear = -1;
}

int isEmpty(QueueType * Q){
    return Q->rear == Q->front;
} //front 와 rear가 만난경우

int isFull(QueueType * Q){
    return Q->rear == (SIZE -1);
}

void enqueue(QueueType * Q, char elem){
    if (isFull(Q)){
        printf("Queue is Full!!\n");
        return;
    }
    Q->rear++;
    Q->data[Q->rear] = elem;
}

char dequeue(QueueType * Q){
    if(isEmpty(Q)){
        printf("Queue is Empty!!!\n");
        return -1;
    }
    Q->front++;
    return Q->data[Q->front];
}

void print(QueueType * Q){
    printf("Front pos : %d, Rear pos : %d \n", Q->front, Q->rear);

    for(int i= Q->front +1; i<= Q->rear; i++){
        printf("[%c]", Q->data[i]);
    }
    printf("\n");

    // while(!isEmpty(Q)){
    //     Q->front ++;
    //     printf("Queue is %c ", Q->data[Q->front]);
    // }
}


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