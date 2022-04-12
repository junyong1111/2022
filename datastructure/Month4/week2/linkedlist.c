#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode{
    char data;
    struct ListNode* next ;

}ListNode; // Node의 구성요소 링크필드 + 데이타 필드

typedef struct{
    ListNode * Head;
}ListType; // 리스트 타입 리스트를 사용 시 이 타입을 선언

void init(ListType *L){
    L->Head = NULL;
}

void insertFirst(ListType *L, char elem){
    ListNode* node =(ListNode*) malloc(sizeof(ListNode)); // 동적으로 메모리 할당
    //Node 초기화
    node->data = elem;
    //데이터 초기화
    node->next = L->Head;
    // 널값 가져오기
    L->Head = node;
    // 이전 노드가 현재 노드를 가르키는 포인터
}

void insertLast(ListType *L, char elem){
    ListNode* node =(ListNode*) malloc(sizeof(ListNode)); // 동적으로 메모리 할당
    node->data = elem;
    node->next = NULL;

    ListNode* p = L->Head;

    if(p==NULL){
        L->Head = node;
    }
    else
    {
    while(p->next != NULL)
        p = p->next;
    p->next = node;
    }

}   

void print(ListType * L){
    ListNode* p; //리스트 노드를 가르키는 빨간 화살표

    for(p = L->Head; p != NULL; p = p->next){
        printf("%c->", p->data);
    }
    printf("\n");
}

int main(void){

    ListType L;
    init(&L);
    insertLast(&L, 'E'); print(&L);
    insertFirst(&L, 'A');  print(&L);
    insertFirst(&L, 'B');  print(&L);
    insertFirst(&L, 'C');  print(&L);
    getchar();

    insertLast(&L, 'D'); print(&L);
   
    return 0;
}