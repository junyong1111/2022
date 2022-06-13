#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

typedef struct HeapType{ //힙 구조체 선언
    int HEAP[SIZE];
    int heapSize;
}HeapType;

void init(HeapType *H){
    H->heapSize = 0;
} //루트는 1부터 시작이므로 0으로 초기화

void Upheap(HeapType *H){ // 삽입한 노드를 올리면서 최대힙을 만드는 과정
    int i = H->heapSize;  // 현재 인덱스 저장
    int key = H->HEAP[i]; // 현재 값을 저장

    while(i!=1 && key>H->HEAP[i/2]){ //루트가 아니거나 부모노드가 더 작다면 반복 수행
        H->HEAP[i] = H->HEAP[i/2]; // 현재 위치와 부모 위치를 바꾸고
        i = i/2; //i 값 갱신
    }
    H->HEAP[i] = key; //마지막 포인트에 값 삽입
}

void DownHeap(HeapType *H){
    int item = H->HEAP[1]; // 루트값 저장
    
    int parent = 1;
    int child = 2;
    
    while(child <= H->heapSize){ //트리 범위내에서
        if((child < H->heapSize) && (H->HEAP[child+1] > H->HEAP[child])) // 오른쪽 형제가 있다면
            child ++; // 오른쪽으로 이동
        if(item >= H->HEAP[child])
            break; // 이동할 필요가 없다면 멈춤
        H->HEAP[parent] = H->HEAP[child];
        parent = child; // 포인트 이동
        child = child *2;
    }
    H->HEAP[parent] = item; // 해당위치 값 삽입
}

void insertitem(HeapType * H, int key){
    H->heapSize++;
    H->HEAP[H->heapSize]= key;
    // 기본적으로 데이터를 넣어주고 
    Upheap(H);
    // 최대힙을 만들기 위해 제일 아래노드부터 올라가야 함
}

int removeMax(HeapType *H){ //루트 값을 빼고 제일 뒷 노드를 다시 올리는 작업
    int item = H->HEAP[1]; //루트값 저장
    int i = H->heapSize--; // 맨 마지막 값을 올리고 크기 줄이기
    H->HEAP[1] = H->HEAP[i];
    DownHeap(H); // 루트부터 내려가면서 최대힙을 만드는 과정
    return item; // 최대값 반환

}

void HeapSort(HeapType * H){
    int N = H->heapSize;
    int A[N];

    for(int i= N-1; i>=0; i--){
        A[i] = removeMax(H);
    }
    for(int i=0; i<N;i++){
        printf("[%d] ", A[i]);
    }
    printf("\n");
}

void print(HeapType *H){
    for(int i=1; i<=H->heapSize; i++){
        printf("[%d]->", H->HEAP[i]);
    }
    printf("\b\b  \n");
}

int main(){
    srand(time(NULL));

    HeapType H;
    init(&H);

    int testCase = rand()%15;
    for(int i=0; i<testCase; i++){
        insertitem(&H, rand()%100);
    }
    print(&H);
    printf("MAX_VALUE IS -> [%d] \n",removeMax(&H));
    print(&H);
    HeapSort(&H);
    return 0;
}