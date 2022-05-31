#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define SIZE 10

/* ----------------------------------------------- */

typedef struct{
    int elem[SIZE];
    int top;
}StackType;


void initStack(StackType* S){
    S->top = -1;
}


int isStackEmpty(StackType* S){
   return S->top == -1;
}


int isStackFull(StackType* S){
    return S->top == SIZE - 1;
}


 
void push(StackType* S, int vName)
{
    if(isStackFull(S)){
        printf("Overflow\n");
        return;
    }

    S->top++;
    S->elem[S->top] = vName;
}


int pop(StackType* S){
    if(isStackEmpty(S)){
        printf("Empty\n");
        return 0;
    }
  
    int vName = S->elem[S->top];
    S->top--;
    return vName;
}


int peek(StackType* S){
    if(isStackEmpty(S)){
        printf("Empty\n");
        return 0;
    }
  
    return S->elem[S->top];
}


/* ----------------------------------------------- */


typedef struct{
int elem[SIZE];
int front, rear;
}QueueType;


void initQueue(QueueType* Q){
Q->front = Q->rear = 0;
}


int isQueueEmpty(QueueType* Q){

return Q->rear == Q->front;
}


 
int isQueueFull(QueueType* Q){

return (Q->rear + 1) % SIZE == Q->front;
}


void enqueue(QueueType* Q, int vName){
    if (isQueueFull(Q)){
        printf("FULL\n");
        return;
        }

Q->rear = (Q->rear + 1) % SIZE;
Q->elem[Q->rear] = vName;
}


int dequeue(QueueType* Q){

    if (isQueueEmpty(Q)){
        printf("EMPTY\n");
        return 0;
}

Q->front = (Q->front + 1) % SIZE;
return Q->elem[Q->front];
}


 
/* ----------------------------------------------- */


typedef struct incidentEdge
{
    int key;
    struct incidentEdge * next;
    
}incidentEdge; //인접엣지는 연결리스트를 계속 추가해주면 된다.

typedef struct Vertex{
    int vKey;
    int isVisit;
    struct Vertex * next;
    incidentEdge * iHead;
}Vertex; 
//정점 또는 노드의 구성요소
// 1. 노드의 들어갈 값
// 2. 노드를 방문했는지 여부
// 3. 다음 노드를 가르킬 포인터
// 4. 해당 노드의 인접엣지를 가르킬 포인터

typedef struct Graph{
    Vertex * vHead;
}Graph;
// 그래프의 연결리스트 표현을 위해 최초 노드

void init(Graph *G){
    G->vHead = NULL;
}
// 초기 헤드의 포인터를 NULL로 지정

void makeVertex(Graph *G, int key){
    Vertex * v = (Vertex*)malloc(sizeof(Vertex));
    v->isVisit = FALSE;
    v->vKey = key;
    v->iHead = NULL;
    v->next = NULL;
// 노드 추가 시 기본셋팅
    Vertex * p = G->vHead;
    if(p==NULL){ //최초의 노드일 경우
        G->vHead = v;
    }
    else{ //최초 노드가 아닐경우
        while(p->next!=NULL)
            p = p->next;
        p->next = v;   
    }
}

void makeIncidentEdge(Vertex *v, int key){
    incidentEdge * E = (incidentEdge*)malloc(sizeof(incidentEdge));
    E->key = key;
    E->next = NULL;
    // 초기 셋팅
    incidentEdge * q = v->iHead;
    // 현재 정점의 인접헤드를 저장
    if(q==NULL){ // 최초의 인접헤드
        v->iHead = E;
    }
    else{ // 비어있는 인접헤드까지 
        while(q->next!=NULL)
            q = q->next;
        q->next = E;
    }
}

Vertex *findVertex(Graph *G, int vKey){
    Vertex * v = G->vHead; 
    while(v->vKey != vKey) //원하는 키까지 간 후
        v = v->next; 


    return v; //해당 정점 반환
}

void insertEdge(Graph *G, int vKey1, int vKey2){
    Vertex * v = findVertex(G,vKey1); //해당 정점을 찾고
    makeIncidentEdge(v,vKey2); // 서로 연결
    v = findVertex(G,vKey2);
    makeIncidentEdge(v,vKey1);
}

void print(Graph *G){
    Vertex * p = G->vHead;
    incidentEdge * q;
    for(; p!=NULL; p= p->next){
        printf("[%d] ",p->vKey);
        for(q = p->iHead; q!=NULL; q= q->next){
            printf("[%d] ", q->key);
        }
        printf("\n");
    }
    printf("\n");
}
void BFS(Graph *G, int Target){
    Vertex *v = findVertex(G, Target);
    incidentEdge *e;
    QueueType Q;
    initQueue(&Q);

    enqueue(&Q, v->vKey);

    while(!isQueueEmpty(&Q)){
        v = findVertex(G,dequeue(&Q));
        if(v->isVisit == FALSE){
            v->isVisit = TRUE;
            printf("[%d] ", v->vKey); 
            for(e=v->iHead; e!=NULL; e = e->next){
                enqueue(&Q, e->key);
            }
        }
    }
}
void initVisit(Graph *G, int node){
    Vertex * v = G->vHead;
    for(int i=0; i<node; i++){
        v->isVisit = FALSE;
        v = v->next;
    }
}
int main(){

    Graph G;
    init(&G);  

    makeVertex(&G, 1); makeVertex(&G, 2); makeVertex(&G, 3);
    makeVertex(&G, 4); 

    insertEdge(&G, 1, 2); insertEdge(&G, 1,3);
    insertEdge(&G, 1,4); insertEdge(&G, 2,4);
    insertEdge(&G, 3,4); 

    print(&G);
    BFS(&G, 1);
    printf("\n");
    return 0;
}