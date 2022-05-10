#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}Node;


void init(Node *deque)
{
    deque->next = NULL;
}

int empty(Node *deque){
    return deque->next == NULL;
}

void push_front(Node *deque, int n)
{
        Node *node = (Node*)malloc(sizeof(Node));
        node->data = n;

        node->next = deque->next;
        deque->next = node;
        
}

void push_back(Node *deque, int n)
{
        Node *node = (Node*)malloc(sizeof(Node));
        Node *p = deque;
        
        while(p->next!=NULL)
        {
            p= p->next;
        }
        node->data = n;

        p->next = node;
        node->next = NULL;
}


int pop_front(Node *deque)
{
        if(empty(deque)){
            return -1;
        }
        Node *p = deque->next;
        int temp = p->data;
        deque->next = p->next;
        free(p);
        return temp;
}

int pop_back(Node *deque)
{
        if(empty(deque)){
            return -1;
        }

        Node *q = deque; //헤드
        Node *p = deque->next;
        while(p->next!=NULL){
            p = p->next;
            q = q->next;
        }
        int temp = p->data;
        q->next = NULL;
        free(p);
        return temp;
}

int size(Node *deque){
    Node *p = deque->next;
    int cnt =0;
    while(p!=NULL){
        p= p->next;
        cnt++;
    }
    return cnt;
}

int front(Node * deque){
     if(empty(deque))
         return -1;
     return deque->next->data;
}

int back(Node * deque){
    if(empty(deque))
        return -1;
    Node *p = deque->next;
    while(p->next!=NULL){
        p = p->next;
    }
    return p->data;
}

void print(Node *deque)
{
    Node *p = deque->next;
    while(p!=NULL){
        cout << p->data <<"\n";
        p = p->next;
    }

}

int main(){
    Node *deque = (Node*)malloc(sizeof(Node));
    init(deque);

    int N = 0;
    cin >> N;
    while(N--){
        string str;
        cin >> str;

        if(str =="push_front"){
            int num =0;
            cin >> num;
            push_front(deque, num);
        }

        else if(str=="push_back"){
            int num = 0;
            cin >> num;
            push_back(deque, num);
        }

        else if (str=="pop_front"){
            cout << pop_front(deque) <<"\n";
        }

        else if (str=="pop_back"){
            cout << pop_back(deque) << "\n";
        }

        else if(str=="size"){
            cout << size(deque) <<"\n";
        }

        else if(str=="empty"){
            cout << empty(deque)<<"\n";
        }
        
        else if(str=="front"){
            cout << front(deque) <<"\n";
        }

        else if(str=="back"){
            cout << back(deque) << "\n";
        }

    }
    

    

    return 0;
}