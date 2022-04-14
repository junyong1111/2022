#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode{
    int coef, expon;
    struct ListNode* next ;

}ListNode; // Node의 구성요소 링크필드 + 데이타 필드

typedef struct{
    ListNode * Head;
    ListNode * Tail;
}ListType; // 리스트 타입 리스트를 사용 시 이 타입을 선언

void init(ListType *L){
    L->Head = NULL;
    L->Tail = NULL;
}

void insertLast(ListType *L, int coef, int expon){
    ListNode* node =(ListNode*) malloc(sizeof(ListNode)); // 동적으로 메모리 할당
    node->coef = coef;
    node->expon = expon;
    node->next = NULL;
    
    if(L->Tail==NULL){
        L->Head = L->Tail = node;
    }
    else
    {
        L->Tail->next = node;
        L->Tail = node;
    }
}   

void polyAdd(ListType *Ans,ListType *poly, ListType *poly1)
{
    ListNode*p = poly->Head;
    ListNode*q = poly1->Head;

    int sum = 0 ;// 지수의 합 저장

    while(p&&q) // p != Null && q != Null
    {
        if(p->expon == q->expon){
            sum = p->coef + q->coef;
            if(sum!=0)
                insertLast(Ans, sum, p->expon);
            p = p->next;
            q = q->next;
        }
        else if(p->expon > q->expon)
        {
            insertLast(Ans, p->coef, p->expon);
            p = p->next;
        }
        else{
            insertLast(Ans, q->coef, q->expon);
            q = q->next;
        }
    }
    for(; p != NULL; p= p->next)
        insertLast(Ans, p->coef ,p->expon);
    for(; q != NULL; q= q->next)
        insertLast(Ans, q->coef ,q->expon);
    
}

void print(ListType * L){
    ListNode* p; //리스트 노드를 가르키는 빨간 화살표

    for(p = L->Head; p != NULL; p = p->next){
        printf("%dx^%d + ", p->coef, p->expon);
    }
    printf("\n");
}

int main(void){

    ListType Ans, poly1, poly2;
    init(&Ans);
    init(&poly1);
    init(&poly2);

    insertLast(&poly1, 3,12);
    insertLast(&poly1, 2,8);
    insertLast(&poly1, 1,0);

    insertLast(&poly2, 8,12);
    insertLast(&poly2, -3,10);
    insertLast(&poly2, -2,8);
    insertLast(&poly2, 10,6);

    print(&poly1);
    getchar();
    print(&poly2);
    getchar();

    polyAdd(&Ans,&poly1,&poly2);
    print(&Ans);
    getchar();
    

    return 0;

}
