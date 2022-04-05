QUEUE 
- 먼저 들어온 데이터가 먼저 나가는 자료구조
- 선입선출(FIFO: First-In-First-Out)
ex) 매표소의 대기열
- 통신에서의 데이터 패킷들의 모델링에 이용
- 프린터와 컴퓨터 사이의 버퍼링
- **스택과** 마찬가지로 프로그래머의 도구
- 많은 알고리즘에서 사용
- 우선순위 QUEUE-> Heep 

구현 

front , rear = -1 로 초기화
rear : 입력
front : 출력

선형큐 
- 배열을 선형으로 사용하여 큐를 구현
##### # 입력이 많으면 overflow가 발생가능함  쓰지않는 메모리가 많아짐
##### 비어있음에도 불구하고 못 쓰는 공간이 생김
##### 결론적으로 선형큐는 사용하지 않는다.
구현
- 


```c++
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
```


원형큐 
- 배열을 원형으로 사용하여 큐를 구현

##### # 입력 rear가 인덱스의 끝에 도달했을 경우 다시 처음으로 돌아가는 방식
##### q->read % size == 0 자신의 인덱스
##### 기존에 구현했던 선형 큐에서 몇 가지 함수만을 수정
##### front , rear = 0으로 초기화
##### front가 가르키는 공간은 항상 공백이여야 함

구현

```c++
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
```

