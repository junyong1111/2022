#include <stdio.h>
#include <stdlib.h>

#define N 10
#define FALSE 0
#define TRUE 1


typedef struct
{
    int stack[N];
    int top;
}StackType;

void initStack(StackType* S)
{
    S->top = -1;
}

int isEmpty(StackType* S)
{
    return S->top == -1;
}

int isFull(StackType* S)
{
    return S->top == N - 1;
}

void push(StackType* S, int e)
{
    if(isFull(S))
        printf("Full\n");
    else
    {
        S->top++;
        S->stack[S->top] = e;
    }
}


int pop(StackType* S)
{
    if(isEmpty(S))
    {
        printf("Empty\n");
        return -1;
    }
    int elem = S->stack[S->top];
    S->top--;
    return elem;
}

int peek(StackType* S)
{
    if(isEmpty(S))
    {
        printf("Empty\n");
        return -1;
    }
    int elem = S->stack[S->top];
    return elem;
}
////////////////////////////////////STACK//////////////////////////////////////


typedef struct
{
char elem[N];
int front, rear;
}QueueType;

void initQueue(QueueType* Q)
{
Q->front = Q->rear = 0;
}

int isQueueEmpty(QueueType* Q)
{
return Q->rear == Q->front;
}

int isQueueFull(QueueType* Q)
{
return (Q->rear + 1) % N == Q->front;
}

void enqueue(QueueType* Q, char vName)
{
if (isQueueFull(Q))
{
printf("FULL\n");
return;
}

Q->rear = (Q->rear + 1) % N;
Q->elem[Q->rear] = vName;
}

char dequeue(QueueType* Q)
{
if (isQueueEmpty(Q))
{
printf("EMPTY\n");
return 0;
}

Q->front = (Q->front + 1) % N;
return Q->elem[Q->front];
}
////////////////////////////////////QUEUE//////////////////////////////////////


// 엣지 정보 구조체
typedef struct IncidentEdge{
    int Inode;
    struct IncidentEdge * Inext;
}IncidentEdge;


// 정점 정보 구조체
typedef struct Vertex{
    int Vnode;
    int isVisit;
    struct Vertex * Vnext;
    struct IncidentEdge * Inext;
}Vertex;

// 그래프의 헤드
typedef struct Graph{
    Vertex * G_head;
}Graph;

// 초기화
void init(Graph *G){
    G->G_head = NULL;
}

// 정점 만들기
void makeVertex(Graph *G, int Node){
    Vertex * V = (Vertex*)malloc(sizeof(Vertex));

    V->Vnode = Node;
    V->isVisit = FALSE;
    V->Inext = NULL;
    V->Vnext = NULL;

    Vertex *p = G->G_head;

    if(p==NULL) //최초의 정점
         G->G_head = V;
    else{
        while(p->Vnext!=NULL)
            p = p->Vnext;
        p->Vnext = V;
    }
}

Vertex *findVertex(Graph *G, int Node){
    Vertex * p = G->G_head;

    while(p->Vnode != Node)
        p = p->Vnext;
    return p;
}

void makeIncidentEdge(Vertex *V, int V2){
    IncidentEdge * E = (IncidentEdge*)malloc(sizeof(IncidentEdge));
    
    E->Inode = V2;
    E->Inext = NULL;

    IncidentEdge * q = V->Inext;

    if(q==NULL)
        V->Inext = E;
    else{
        while(q->Inext !=NULL)
            q = q->Inext;
        q->Inext = E;
    }

}

void insertEdge(Graph *G, int V1, int V2){
    Vertex *V = findVertex(G,V1);
    makeIncidentEdge(V, V2);
    V = findVertex(G,V2);
    makeIncidentEdge(V, V1);
}

void BFS(Graph *G, int Target){
    Vertex *V = findVertex(G, Target);
    IncidentEdge *E;

    QueueType Q;
    initQueue(&Q);

    V->isVisit = TRUE;
    printf("[%d] ", V->Vnode);
    enqueue(&Q, V->Vnode);

    while(!isQueueEmpty(&Q)){
        V = findVertex(G, dequeue(&Q));
        for(E=V->Inext; E!=NULL; E= E->Inext){
            V =findVertex(G,E->Inode);
            if(V->isVisit == FALSE){
                V->isVisit = TRUE;
                printf("[%d] ", V->Vnode);
                enqueue(&Q, V->Vnode);
            }
        }
    }
}

void DFS(Graph *G, int Target){
    Vertex *V = findVertex(G, Target);
    IncidentEdge *E;

    StackType S;
    initStack(&S);

    push(&S, V->Vnode);

    while(!isEmpty(&S)){
        V = findVertex(G, peek(&S));
        if(V->isVisit == FALSE){
            V->isVisit = TRUE;
            printf("[%d] ", V->Vnode);
        }

        for(E=V->Inext; E!=NULL; E= E->Inext){
            V = findVertex(G, E->Inode);
            if(V->isVisit == FALSE){
                push(&S, V->Vnode);
                break;
            }
        }
        if(E==NULL)
            pop(&S);
    }
}



void print(Graph *G){
    Vertex *p = G->G_head;
    IncidentEdge *q;

    for(; p!=NULL; p=p->Vnext){
        printf("[%d] ", p->Vnode);
        for(q= p->Inext; q!=NULL; q= q->Inext){
            printf("[%d] ", q->Inode);
        }
        printf("\n");
    }
    printf("\n");
}





int main(){
    
    Graph G;
    init(&G);

    
    makeVertex(&G, 1); makeVertex(&G, 2); makeVertex(&G, 3);
    makeVertex(&G, 4); makeVertex(&G, 5); makeVertex(&G, 6);
    makeVertex(&G, 7); makeVertex(&G, 8);

    insertEdge(&G, 1, 2); insertEdge(&G, 1, 3);
    insertEdge(&G, 2, 4); insertEdge(&G, 2, 5);
    insertEdge(&G, 3, 5); insertEdge(&G, 5, 6);
    insertEdge(&G, 6, 7); insertEdge(&G, 7, 8);

    print(&G);

    // DFS(&G,1);
    printf("\n");
    BFS(&G,1);

    
    
    return 0;
}