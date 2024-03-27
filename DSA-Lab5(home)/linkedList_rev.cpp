#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int newData){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = head;
    head = newNode;
}

void revDisplay(){
    struct Node* ptr;
    ptr = head;
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main(){
    int testCases;
    int length;
    int element;

    cin >> testCases;
    for(int i = 0; i < testCases; i++){
        cin >> length;
        for(int j = 0; j < length; j++){
            cin >> element;
            insert(element);
        }
        revDisplay();
    }
}
