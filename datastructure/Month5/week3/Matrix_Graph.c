#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct Graph
{
    int num_Vertex;
    int adjM[N][N];
}Graph; //그래프를 표현 할 인접행렬

void init(Graph *G){
    G->num_Vertex = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            G->adjM[i][j] = 0;
        }
    }
} // 인접행렬의 모든 관계를 0으로 초기화

void makeVertex(Graph *G){
    G->num_Vertex++;
} // 노드를 한개 추가

int indexError(Graph *G, int u, int v){
    if(G->num_Vertex <= u || G->num_Vertex <= v)
        return 1;
    return 0;
}

void insertEdge(Graph *G, int u, int v){
    if(indexError(G,u,v))
        printf("INDEX ERROR!!\n");
    else{
        G->adjM[u][v] = 1;
        G->adjM[v][u] = 1; 
        //무방향 그래프의 경우  주대각원소를 기준으로 서로 대칭행렬이므로해당 INDEX에 1를 넣어준다.
    }
}

void print(Graph *G){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("[%d]", G->adjM[i][j]);
        }
        printf("\n");
    }
}


int main(){
    Graph G;
    init(&G);

    int n = 5;
    for(int i=0; i<n; i++)
        makeVertex(&G);
    
    insertEdge(&G, 0, 1); insertEdge(&G, 0, 2); insertEdge(&G, 0, 3);
    insertEdge(&G, 1, 2); insertEdge(&G, 2, 3);
    print(&G);


    return 0;
}