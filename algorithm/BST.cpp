#include <iostream>

using namespace std;

typedef struct Node{
    int data;
    struct Node * L ;
    struct Node * R ;
    struct Node * P ;
}Node;

void init(Node* Root){
    Root->L = NULL;
    Root->R = NULL;
    Root->P = NULL;
}

void insert(Node* Root, int e){
    Node *node = new Node;
    Node *p = Root;
    if(p->L == NULL){
        node->data = e;
        node->P = p;
        p->L = node;

    }
    else{
        node->data = e;
        node->P = p;
        p->R = node;
    }
}

int main(){
    Node * Root = new Node;
    init(Root);
    insert(Root, 10);
    insert(Root, 20);
    cout << Root->L->data << " " << Root->R->data <<"\n";

    return 0;
}