#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct 
{
    int heap[N];
    int heapSize;
}HeapType;

void init(HeapType* H){
    H->heapSize = 0;
}

void UpHeap(HeapType *H){
    int i = H->heapSize; // 힙의 크기를 임시 저장 
    int key = H->heap[i]; //

    while((i!=1) && (key > H->heap[i/2])){
        H->heap[i] = H->heap[i/2]; //위치를 바꾸고
        i = i/2; // 포인트를 부모노드로 
    } //루트가 아니고 부모노드보다 더 크다면 반복 지속
    H->heap[i] = key; // 최대 힙에 맞게 키값 삽입
}

void DownHeap(HeapType *H){
    int item = H->heap[1]; //루트로 올라간 Key를 저장
    int parent = 1; 
    int child = 2; // 왼쪽으로만 내려가는 화살표

    while( child <= H->heapSize){ //트리의 범위 안에서
        if((child< H->heapSize )&&(H->heap[child+1] > H->heap[child])){//오른쪽 형제가 있는지 확인 후 화살표가 오른쪽으로
            child ++;
        }
        if(item >= H->heap[child]){ //현재 아이템값이 더 큰 경우 해야할 일 없음
            break; 
        }
        H->heap[parent] = H->heap[child];
        parent = child;
        child = child * 2;
    } //while
    H->heap[parent] = item;
}

int removeItem(HeapType *H){
    int item = H->heap[1]; // 루트값을 저장
    H->heap[1] = H->heap[H->heapSize]; // 제일 밑 노드를 루트노드로 올린다.
    H->heapSize --; // Heap사이즈 한개 감소
    DownHeap(H);
    return item;
}

void insertItem(HeapType *H, int key){
    H->heapSize ++; // 크기를 하나 증가시킴
    H->heap[H->heapSize] = key; // 증가시킨 곳에다가 Key값을 삽입
    UpHeap(H); //최대힙을 만드는 과정
}

void printHeap(HeapType *H){
    for(int i=1; i<=H->heapSize; i++)
        printf("(%d)", H->heap[i]);
    printf("\n");
}

int main(){
    HeapType H;
    init(&H);

    insertItem(&H, 9); insertItem(&H, 7); insertItem(&H, 6);
    insertItem(&H, 5); insertItem(&H, 4); insertItem(&H, 3);
    insertItem(&H, 2); insertItem(&H, 2); insertItem(&H, 1);
    insertItem(&H, 3); printHeap(&H); getchar();

    // insertItem(&H, 8); printHeap(&H);
    removeItem(&H); printHeap(&H);


    return 0;
}