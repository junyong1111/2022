#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct IncidentEdge{
     char aName;
     struct IncidentEdge* next;
}IncidentEdge;

typedef struct Vertex{
    char vName;
    int isVisit;
    IncidentEdge* iHead;
    struct Vertex* next;

}Vertex;

typedef struct{
    Vertex* vHead;
}GraphType;


void init(GraphType *G){
    G->vHead = NULL;
}


void makeVertex(GraphType *G, char vName){
    Vertex* v = (Vertex *)malloc(sizeof(Vertex));
    int isVisit = FALSE;
    v->vName = vName;
    v->iHead = NULL;
    v->next = NULL;
    Vertex* p = G->vHead;

    if(p == NULL)
      G->vHead = v;
    else
  {
        while(p->next != NULL)
            p = p->next;
        p->next = v;    
    }
}


Vertex* findVertex(GraphType* G, char vName){
    Vertex* v = G->vHead;
    while(v->vName != vName)
        v = v->next;

    return v;    
}

void makeIncidentEdge(Vertex * V, char aName){
    IncidentEdge *P = (IncidentEdge*)malloc(sizeof(IncidentEdge));
    P->aName = aName;
    P->next = NULL;
    
    IncidentEdge *Q = V->iHead;
    if(Q==NULL){
        V->iHead = P;
    }

    else{
        while(Q->next != NULL)
            Q = Q->next;
        Q->next = P;
    }
}

 
void insertEdge(GraphType* G, char v1, char v2){
    Vertex* v = findVertex(G, v1);
    makeIncidentEdge(v, v2);
    v = findVertex(G, v2);
    makeIncidentEdge(v, v1);
}


void rDfs(GraphType *G, char vName){
    Vertex* v = findVertex(G, vName);
    IncidentEdge *p;

    if(v->isVisit == FALSE){
        v->isVisit =  TRUE;
        printf("(%c) ", v->vName);
    }

    for(p = v->iHead; p!=NULL; p= p->next){
        v = findVertex(G, p->aName);
        if(v->isVisit == FALSE){
            rDfs(G,v->vName);
        }
    }

}

void print(GraphType* G){
    Vertex* p = G->vHead;
    IncidentEdge *q;

    for(; p != NULL; p = p->next){
        printf("[%c] : ", p->vName);
        for(q = p->iHead; q!=NULL; q= q->next)
            printf("[%c] ", q->aName);
        printf("\n");
    }
}


int main(){

    GraphType G;
    init(&G);
 
    makeVertex(&G, 'a'); makeVertex(&G, 'b');
    makeVertex(&G, 'c'); makeVertex(&G, 'd'); makeVertex(&G, 'e');
    insertEdge(&G, 'a', 'b'); insertEdge(&G, 'a', 'c');
    insertEdge(&G, 'a', 'e'); insertEdge(&G, 'b', 'c');
    insertEdge(&G, 'c', 'd'); insertEdge(&G, 'c', 'e');
    insertEdge(&G, 'd', 'e'); print(&G);

    rDfs(&G, 'd');


    return 0;
}