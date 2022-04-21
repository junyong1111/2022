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