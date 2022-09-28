#include <iostream>

using namespace std;

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

void insert(Node** root, int data);
void preOrder(Node* root);
void inOrder(Node* root);
void postOrder(Node* root);
int size(Node* root);
int height(Node* root);
int sumOfWeigh(Node* root);
int maxPathWeight(Node* root);
void mirror(Node** root);
void destruct(Node** root);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int num = 0;
        cin >> num;
        Node* root = NULL;
        for(int i=0; i<num; i++){
            int data = 0;
            cin >> data;
            insert(&root, data);
        }   
        cout << size(root) <<"\n";
        cout << height(root)-1 <<"\n";
        cout << sumOfWeigh(root) << "\n";
        cout << maxPathWeight(root) << "\n";
        mirror(&root);
        preOrder(root); cout <<"\n";
        inOrder(root); cout << "\n";
        postOrder(root); cout << "\n";
        destruct(&root);

        if(root == NULL)
            cout << "0\n";
        else    
            cout << "1\n";
    }
    return 0;
}



void insert(Node** root, int data){
    if(*root==NULL){
        Node *node = new Node;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        *root = node;
    }
    else{
        if((*root)->data <data){// 더 큰 경우 오른쪽
            insert(&((*root)->right),data);
        }
        else if((*root)->data > data){// 작왼
            insert(&((*root)->left),data);
        }  
    }
    
}
void preOrder(Node* root){
    if(root){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Node* root){
    if(root){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
void postOrder(Node* root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

}
int size(Node* root){
    int cnt = 0;
    if(root){
        cnt++;
        cnt += size(root->left);
        cnt += size(root->right);
    }
    return cnt;
}
int height(Node* root){
    int h = 0;
    int hl = 0;
    int hr = 0;
    if(root){
        h++;
        hr = h +height(root->right);
        hl = h + height(root->left);
    }
    return hr<hl?hl:hr;
}
int sumOfWeigh(Node* root){
    int sum = 0;
    if(root){
        sum += root->data;
        sum += sumOfWeigh(root->left) +sumOfWeigh(root->right);
    }
    return sum;
}
int maxPathWeight(Node* root){
    int max_sum = 0;
    int left_max = 0;
    int right_max = 0;
    if(root){
        max_sum += root->data;
        left_max = maxPathWeight(root->left);
        right_max = maxPathWeight(root->right);
    }
    return max_sum + (left_max <= right_max?right_max :left_max);
}

void mirror(Node** root){
    if(*root!=NULL){
        Node * TempNode = (*root)->left;
        (*root)->left = (*root)->right;
        (*root)->right = TempNode;
        mirror(&((*root)->left));
        mirror(&((*root)->right));

    }
}

void destruct(Node** root){
    if(*root!=NULL){
        destruct(&((*root)->left));
        destruct(&((*root)->right));
        *root = NULL;
    }
}