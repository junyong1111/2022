# Doubly linked list (이중연결리스트)

기존에 구현했던 연결리스트는 이동방향이 하나라서 그 전에 값을 읽으려면 다시 처음부터 돌아와야하지만 이중연결리스트는 양방향이라 앞뒤로 포인터의 이동이 가능하다.


1. Doubly_linked_list.c 
    - 기존 연결리스트와는 다르게 전체리스트의 시작 또는 끝을 표시하는 포인터가 없다 노드로만 구현
- 구현방법
    - 기존 연결리스트는 data , link 필드 2가지로 구성되었지만 이중연결리스트는 앞 뒤로 이동을 해야하기때문에 노드의 다음값인 next값과 노드의 이전값인 prev값을 저장 필요 **총 3개의 필드 필요**
    - 전체 리스트의 시작을 나타내는 헤드 필드가 존재하지않으므로 노드만으로 구현가능

### 구현 

함수 설명

- 3개의 필드(데이터, 이전포인터,다음포인터)를 가진 구조체 선언
```c++
typeder struct DListNode{
    char data;
    struct DListNode* prev, * next;
}DListNode
```

- void init( DListNode *H, DListNode *T )  
함수 시작 시 처음과 끝 노드를 생성

- void insert(DListNode *H , int pos ,char elem)  
원하는 위치에 노드를 생성한 후 데이터 입력하여 
노드를 삽입 후 그 전 노드의 next값과 이 후 노드의 prev값을 현재 새로 만들어준 노드와 연결하는 과정이 필요하다.

- char delete(DListNode *H , int pos)  
원하는 위치에 노드를 제거 한 후 그 값을 return   
지워진 노드의 prev,next값을 다른 노드와의 연결작업 필요

- void print(DListNode *H, DListNode *T)  
노드의 시작부터 끝까지의 데이터안에 들어있는 값을 하나씩 출력

위 개념을 가지고 실제 구현
<details>
<summary> 구현 코드 </summary>
<div markdown="1"> 

```c++
#include <stdio.h>
#include <stdlib.h>

typedef struct DListNode
{
    char data;
    struct DListNode* prev, * next;
}DListNode;


void init( DListNode *H, DListNode *T ){
    H->next = T;
    T->prev = H;
}

void insert(DListNode *H , int pos ,char elem){
    DListNode *p = H;
    for(int i=1; i< pos; i++){
        p = p->next;
    }
     DListNode *node = (DListNode*)malloc(sizeof(DListNode));
    node->data = elem;
    node->prev = p;
    node->next = p->next;
    p->next->prev = node;
    // node->next->prev = node;
    p->next = node;
}

char delete(DListNode *H , int pos){
    DListNode *p = H;
    for(int i=1; i<= pos; i++){
        p = p->next;
    }
    char temp = p->data; //임시로 저장
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    return temp; 
}

void print(DListNode *H, DListNode *T){
    for(DListNode *p = H->next; p!=T; p=p->next){
        printf(" %c <=>", p->data);
    }
    printf("\b\b\b   \n");
}


int main(){
    DListNode *H = (DListNode*)malloc(sizeof(DListNode));
    DListNode *T = (DListNode*)malloc(sizeof(DListNode));

    init(H,T); // 포인터는 이미 주소임

    insert(H, 1, 'A'); print(H,T);
    insert(H, 1, 'B'); print(H,T);
    insert(H, 2, 'C'); print(H,T);
    insert(H, 4, 'D'); print(H,T);
    getchar();

    printf("Delete node Number: ");
    int pos;
    scanf("%d ", &pos);
    printf("%c is deleted\n",delete(H, pos));
    print(H,T);

    return 0;
}

```

</div>
</details>

2. Doubly_linked_head.c
    - 위에서 구현했던 이중연결리스트와는 조금 다르게 전체의 시작을 가르키는 HEAD필드가 존재 노드+리스트
-  구현방법
    - 기존 연결리스트와 위의 이중연결리스트 구현방법을 혼합 
    
### 구현

함수설명  

```c++
typedef struct
{
    DListNode * Head;
}DListType;
```
전체의 시작점을 알려줄 HEAD 구조체 선언

- void init( DListType *DL)  
기존 연결리스트와 마찬가지로 제일 시작점인 HEAD 포인터의 값을 NULL로 지정

- void insertFirst(DListType *DL, char elem)  
노드의 가장 앞 부분에 리스트를 삽입 기존 연결리스트와 동일하지만 추가적으로 앞 뒤가 더 있는 경우

- void insert(DListType * DL, int pos, char elem)  
원하는 노드 위치에 해당 값을 삽입 기존 연결리스트 + 이중연결리스트라 생각하면 편함

위 개념을 가지고 실제 구현

<details>
<summary> 구현 코드 </summary>
<div markdown="1"> 

```c++
#include <stdio.h>
#include <stdlib.h>

typedef struct DListNode
{
    char data;
    struct DListNode* prev, * next;
}DListNode;

typedef struct
{
    DListNode * Head;
}DListType;


void init( DListType *DL){
    DL->Head = NULL;
}

void insertFirst(DListType *DL, char elem)
{
    DListNode *node = (DListNode*)malloc(sizeof(DListNode));
    DListNode *p = DL->Head;
    node->data = elem;
    node->prev = NULL;
    node->next = p;
    DL->Head = node;

    if(p!=NULL){
        p->prev = node;
    }
}

void insert(DListType * DL, int pos, char elem){
    DListNode *node = (DListNode*)malloc(sizeof(DListNode));
    DListNode *p = DL->Head;

    if(pos==1){
        insertFirst(DL, elem);
    }
    else{
        for(int i=1; i<pos; i++)
            p = p->next;
        node->data = elem;
        node->prev = p->prev;
        node->next = p;
        node->prev->next =node;
        node->next->prev = node;
        
    }
}

void print(DListType * DL){
    for(DListNode *p = DL->Head; p!=NULL; p=p->next){
        printf(" %c <=>", p->data);
    }
    printf("\b\b\b   \n");
}


int main(){
    DListType DL;
    init(&DL);
    insertFirst(&DL , 'A'); print(&DL);
    insertFirst(&DL , 'B'); print(&DL);
    insertFirst(&DL , 'C'); print(&DL);
    insertFirst(&DL , 'D'); print(&DL);
    getchar();

    printf("Insert G in pos 2\n");
    insert(&DL ,2 ,'G'); 
    getchar();
    print(&DL);
    getchar();
    
    printf("Insert D in pos 3\n");
    insert(&DL ,3 ,'D');
    getchar();
    print(&DL);
    getchar();

    printf("Insert B in pos 4\n");
    getchar();
    insert(&DL ,4 ,'B');
    print(&DL);

    return 0;
}

```

</div>
</details>

