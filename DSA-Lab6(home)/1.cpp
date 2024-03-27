#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int value){
            data = value;
            right = NULL;
            left = NULL;
        }
};

Node * insert(Node * root, int data) {
        if(root == NULL){
            root = new Node(data);
            return root;
        }
        else if(data >= root->data){
            root->right = insert(root->right, data);
        }
        else if(data < root->data){
            root->left = insert(root->left, data);
        }
        return root;
    }

Node* commonAncestor(Node* root, int val1, int val2){
    if(root == NULL){
        //cout << "no common ancestor" << endl;
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

bool check(Node* node, int v1) {
    if (node == NULL) {
        return false;  // Value not found
    }

    if (node->data == v1) {
        return true;   // Value found
    }

    // Recursively check the left and right subtrees
    bool leftResult = check(node->left, v1);
    bool rightResult = check(node->right, v1);

    // Return true if the value is found in either subtree
    return leftResult || rightResult;
}

int main(){
    Node* root = NULL;
    int nodes;
    int data;
    cin >> nodes;
    cin >> data;
    root = insert(root,data);
    for(int i=0; i < nodes; i++){
        cin >> data;
        insert(root, data);
    }
     int val1,val2;
     cin >> val1;
     cin >> val2;
    // if(check(root,val1) == true && check(root,val2) == true){
    cout << commonAncestor(root,val1,val2)->data;  
    // }
}