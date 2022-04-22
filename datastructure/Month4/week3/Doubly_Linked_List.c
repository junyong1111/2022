#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data ;
    struct Node *prev;
    struct Node *next;
}Node;

typedef struct Doubly{
    Node * HEAD;
}Doubly;

void init(Doubly *DL){
    DL->HEAD = NULL;
}

int posError(Doubly *DL, int pos){
    Node *point = DL->HEAD;
    int cnt = 1;
    while(point!=NULL){
        point = point->next;
        cnt ++;
    }
    if(pos<=0 || pos>=cnt){
        return 1;
    }
    else{
        return 0;
    }

}

void insertFirst(Doubly *DL, int elem){
    Node *node = (Node*)malloc(sizeof(Node));
    Node *point = DL->HEAD;
    while(point!=NULL)
        point = point->next;
    node->data = elem;
    node->next = DL->HEAD;
    DL->HEAD = node;
    node->prev = point;

    // printf("Curr node### is %p======================\n",node);
}

void insertLast(Doubly *DL, int elem){
    Node *node = (Node*)malloc(sizeof(Node));
    Node *point = DL->HEAD;
    // printf("Curr HEAD point### is %p======================\n",point);

    if(point==NULL){
        insertFirst(DL,elem);
    }
    else{   
         
    while(point->next!=NULL)
    {
        point = point->next;
        //printf("Curr point### is %p======================\n",point);
    }
    node->data = elem;
    node->next = NULL;
    
    point->next = node;
    node->prev = point;
    }
}

void insert(Doubly *DL, int pos, int elem){
    if(pos==1){insertFirst(DL,elem);}

    else if(posError(DL,pos)){
        printf("POS ERROR=========== \n");
    }
    else{
        
        Node *node = (Node*)malloc(sizeof(Node));
        Node *point = DL->HEAD;
        for(int i=1; i<pos-1; i++){
            point = point->next;
        }
        
        node->data = elem;
        node->prev = point;
        node->next = point->next;

        point->next->prev = node;
        point->next = node;
    }
}

int deleteFirst(Doubly *DL){
    Node *point = DL->HEAD;
    DL->HEAD = point->next;
    point->next->prev = DL->HEAD;
    int temp = point->data;
    free(point);
    return temp;
}

int deleteLast(Doubly *DL){
    Node *point = DL->HEAD;
    while(point->next!=NULL){
        point = point->next;
    }
    int temp = point->data;
    point->prev->next = NULL;
    free(point);
    return temp;
}

int delete(Doubly *DL, int pos)
{
    int temp =0;
    if(posError(DL,pos)){ printf("POS ERROR!!\n"); return -1; }
    else 
    {
        if(pos==1){return deleteFirst(DL);}

        else {
                Node *point = DL->HEAD;
                Node *depoint = DL->HEAD;
                for(int i=1; i<pos-1; i++)
                    depoint = depoint->next;
                for(int i=1; i<pos; i++)
                    point = point->next; 
                temp = point->data;
                point->next->prev = point->prev;
                depoint->next = point->next;
                free(point);
                return temp;
            }   
    }

}

int serach(Doubly *DL, int find){
    Node *point = DL->HEAD;
    int cnt =1;
    while(point!=NULL){

        if(find == point->data){
            printf("Find %d!!\n",point->data);
            printf("INDEX IS %d\n", cnt);
            return find;
        }
            point = point->next;
            cnt++;
        } //while
        printf("NOT FIND !!\n");
        return -1;
}

void print(Doubly *DL){
    Node *point = DL->HEAD;
    for(; point!=NULL; point= point->next){
        printf("%d -> ", point->data);
    }
    printf("\b \n");
}



int main(){
    Doubly DL;
    init(&DL);
    insertFirst(&DL,2); insertFirst(&DL,1); insertFirst(&DL,0); print(&DL); getchar();
    insertLast(&DL,1); insertLast(&DL,0); print(&DL); getchar();

    insert(&DL,1,-2); print(&DL); getchar();

    insert(&DL,2,-1); print(&DL); getchar();

    serach(&DL, -1);

    insert(&DL,20,-1); print(&DL); getchar();

    insert(&DL,7,-10); print(&DL); getchar();

    printf("%d is deleted !!\n",deleteFirst(&DL)); print(&DL); getchar();
    printf("%d is deleted !!\n",deleteFirst(&DL)); print(&DL); getchar();
    printf("%d is deleted !!\n",deleteLast(&DL)); print(&DL); getchar();
    printf("%d is deleted !!\n",deleteLast(&DL)); print(&DL); getchar();
    printf("%d is deleted !!\n",delete(&DL,1)); print(&DL); getchar();
    printf("%d is deleted !!\n",delete(&DL,2)); print(&DL); getchar();

    return 0;
}