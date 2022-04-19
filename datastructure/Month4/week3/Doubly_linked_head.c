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