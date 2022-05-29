#include <stdio.h>
#include <stdlib.h>

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
    v->isVisit = 0;
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

    return 0;
}