#include<iostream>
//Binary Search Tree
using namespace std;
//Defining a Node
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node Node;

Node *NewNode(int value){
    struct Node *temp = (Node *)malloc(sizeof(Node));
    temp -> data = value;
    temp -> left = temp -> right = nullptr;
    return temp;
}
Node *insert(Node *node, int data){
    if(node == nullptr){
        return NewNode(data);
    }
    else{
        if(data < node->data){
            node->left = insert(node->left,data);
        }
        else{
            node->right = insert(node->right,data);
        }
    }
    return node;
}
void inorder(Node *node){
    if (node == nullptr) return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
int main(){
    Node *root = nullptr;
    root = insert(root,10);
    root = insert(root,0);
    root = insert(root,1);
    root = insert(root,11);
    root = insert(root,12);
    inorder(root);
}
