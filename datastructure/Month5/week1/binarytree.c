#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode{
    element key;
    struct TreeNode * left;
    struct TreeNode * right;
}TreeNode;

TreeNode * insertNode(TreeNode* Root, element key){
    if(Root == NULL){ // 루트노드가 비어있다면 새로운 노드 생성
        TreeNode * node = (TreeNode*)malloc(sizeof(TreeNode));
        node->key = key;
        node->left = NULL; //자식이 없는 단말노드
        node->right = NULL; //자식이 없는 단말노드
        return node; // 만들어진 노드의 주소를 반환
    } 
    // 루트가 NULL이 아닌경우 노드가 들어갈 위치를 찾아야 함(재귀적으로)

    if(key < Root->key) //들어올 key값과 root의 key를 비교 같은경우는 아무것도 하지않는다.
        Root->left = insertNode(Root->left,key);
    else if(key > Root->key)
        Root->right = insertNode(Root->right, key);
    return Root;
}

void preOrder(TreeNode * Root){// 전위 순회 V->L->R
    if(Root){
        printf("[%d] ", Root->key);
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder(TreeNode * Root){ //중위 순회 L->V->R 내림차순 정렬이기도 하다.
    if(Root)
    {
        inOrder(Root->left);
        printf("[%d] ", Root->key);
        inOrder(Root->right);
    }

}

void postOrder(TreeNode * Root){ //후위 순회 L->R->V
    if(Root){
        postOrder(Root->left);
        postOrder(Root->right);
        printf("[%d] ", Root->key);
    }
}

int get_node_count(TreeNode * Root){ //노드의 개수를 카운트
    int count = 0;
    if(Root!=NULL){ // 루트(부모)가 NULL이 아니라면 갯수를 1개 추가 하고 왼쪽 노드와 오른쪽 노드 확인
        count = 1 + get_node_count(Root->right) + get_node_count(Root->left);
    }
    return count ; // 총 갯수를 반환
}




int main(){

    TreeNode * Root = NULL;
    Root = insertNode(Root, 35); //날라오는 주소를 받아줘야한다.
    Root = insertNode(Root, 68);
    Root = insertNode(Root, 99);
    Root = insertNode(Root, 18);
    Root = insertNode(Root, 7);
    Root = insertNode(Root, 3);
    Root = insertNode(Root, 12);
    Root = insertNode(Root, 26);
    Root = insertNode(Root, 22);
    Root = insertNode(Root, 30);
    preOrder(Root);
    printf("\n");
    inOrder(Root);
    printf("\n");
    postOrder(Root);
    printf("\n");
    printf("Node is %d\n",get_node_count(Root));
    return 0;
}