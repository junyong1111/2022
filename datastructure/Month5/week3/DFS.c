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


void DFS(Graph *G, int Target){
    // Step1.시작 정점을 찾는다
    Vertex *V = findVertex(G, Target);
    IncidentEdge *E;
    // Step2.스택 생성 및 초기화
    StackType S;
    initStack(&S);

    // Step3.첫 정점 푸쉬
    push(&S, V->Vnode);
    // Step4. 스택의 원소가 없을때까지
    while(!isEmpty(&S)){
        // 스택의 최상단의 정점을 찾음 -> 방문체크 -> 출력 -> 인접노드 확인 방문하지않은 노드가 나오면 push -> break;
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
        // Step5. 만약 인접노드를 다 방문 했다면 해당 노드 삭제
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

    DFS(&G,1);

    
    
    return 0;
}