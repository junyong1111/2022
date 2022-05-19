#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct{
    int stack[N];
    int top;
}StackType;

void initStack(StackType* S){
    S->top = -1;
}


int isEmpty(StackType* S){
    return S->top == -1;
}


int isFull(StackType* S){
    return S->top == N - 1;
}


void push(StackType* S, int e){
    if(isFull(S))
        printf("Full\n");
    else
    {
        S->top++;
        S->stack[S->top] = e;
    }
}


int pop(StackType* S){
    if(isEmpty(S))
    {
        printf("Empty\n");
        return -1;
    }
    int elem = S->stack[S->top];
    S->top--;
    return elem;
}
///////////////////////// STACK //////////////////////

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

void heapSortV1(HeapType *H){ //힙 정렬 정렬을 위해 필요한 배열을 추가적으로 생산하는 방법
    int n = H->heapSize; // 힙 사이즈를 미리 저장해둬야 함
    int A[n]; // 정렬을 위해 필요한 공간

    for(int i=n-1; i>=0; i--) // n만큼 반복
        A[i] = removeItem(H); //삭제 연산은 logn 
        // 따라서 힙정렬은  O(n*logn)
    
    for(int i=0; i<n; i++)
        printf("(%d)", A[i]);
    printf("\n");
} 

void heapSortV2(HeapType *H){
    int n = H->heapSize;

    for(int i=1; i<=n; i++){ //직접적으로 넣어줄 배열이 없음
        int key = removeItem(H); // 리턴받은 루트값을 저장 -> 힙 사이즈가 하나씩 감소함
        H->heap[H->heapSize+1] = key; 
    }

    for(int i=1; i<=n; i++)
       printf("(%d)", H->heap[i]);
    printf("\n");
}

void binaryExpansion(StackType *S , int i){
    while(i>=2){
        push(S,i%2);
        i = i/2;
    }
    push(S,1); //루트는 1
}

void findLastNode(HeapType *H){
    StackType S;
    initStack(&S);
    int value;
    int nodeNum = 1;
    binaryExpansion(&S, H->heapSize); //노드의 마지막 번호를 이진수로 만들어서 스택에 저장하는 함수
    pop(&S); //루트를 버림

    while(!isEmpty(&S)){
        int bit = pop(&S); // 한비트씩 빼냄
        printf("%d", bit); //동작하고는 상관없는 확인용 출력문

        if(bit == 0){
            nodeNum = nodeNum * 2 ; //왼쪽으로 감
            value = H->heap[nodeNum];
        }
        else{
           nodeNum = nodeNum * 2+1 ; //오른쪽으로 감
           value = H->heap[nodeNum];
        }
    }

    printf("\nLast Node : %d\n", value);
    
}

void printHeap(HeapType *H){
    for(int i=1; i<=H->heapSize; i++)
        printf("(%d)", H->heap[i]);
    printf("\n");
}
//////////////////////////// HEAP //////////////////////////////


int main(){
    HeapType H;
    init(&H);

    insertItem(&H, 9); insertItem(&H, 7); insertItem(&H, 6);
    insertItem(&H, 5); insertItem(&H, 4); insertItem(&H, 3);
    insertItem(&H, 2); insertItem(&H, 2); insertItem(&H, 1);
    insertItem(&H, 3); printHeap(&H); getchar();

    // insertItem(&H, 8); printHeap(&H);
    removeItem(&H); printHeap(&H);
    getchar();
    // heapSortV1(&H);
    // getchar();
    heapSortV2(&H);
    getchar();

    findLastNode(&H);

    return 0;
}