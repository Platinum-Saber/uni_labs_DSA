#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
};

Node* insertNode(Node* root, int data){
    if(root == NULL){
        root = new Node();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if(data > root->data){
        root->right = insertNode(root->right, data);
    }
    else if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    return root;
    
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

Node* commonAncestor(Node* root, int val1, int val2){
    if(root == NULL){
        cout << "no common ancestor" << endl;
        return root;
    }
    if(val1 > root->data && val2 > root->data){
        return commonAncestor(root->right, val1, val2);
    }
    else if(val1 < root->data && val2 < root->data){
        return commonAncestor(root->left, val1, val2);
    }
    else{
        return root;
    }
}



int main(){
    Node* root = NULL;
    root = insertNode(root,20);
    insertNode(root, 30);
    // insertNode(root, 15);
    // insertNode(root, 25);
    // insertNode(root, 10);
    // insertNode(root, 16);
    // insertNode(root,35);

    cout << commonAncestor(root, 20, 30)->data << endl;
    preOrder(root);
}
