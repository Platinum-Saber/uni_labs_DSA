#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    //Default constructor
        Node(){
            data = 0;
            Node* next;
        }

    //Parametered constructor
        Node(int newData){
            this->data = newData;
            this->next = nullptr;
        }
};

class linkedList{

    public:
        Node* head;
        linkedList(){
            head = nullptr;
        }
        void insertNode(int);
        void display();
        //void deleteNode(int);
};

void linkedList :: insertNode(int data){
    Node* newNode = new Node(data);
    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void linkedList :: display(){
    Node* temp = head;
    if(head == nullptr){
        cout << "List empty" << endl;
        return;
    }
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void reversePrint(Node* llist_head){
    Node* temp = llist_head;
    if(temp == nullptr){
        return;
    }
    reversePrint(temp->next);
    cout << temp->data << " ";
    
}

int main(){
    linkedList llist;
    llist.insertNode(3);
    llist.insertNode(7);
    llist.insertNode(1);
    cout << "Linked list is: ";
    llist.display();
    cout << "reversed Linked list is: ";
    reversePrint(llist.head);
    return 0;
}






