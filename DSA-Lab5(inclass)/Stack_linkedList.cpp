#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;  

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            std::cerr << "Stack Underflow" << std::endl;
            exit(EXIT_FAILURE);
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    int stackTop() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            exit(EXIT_FAILURE);
        }
        return top->data;
    }

    void display() const {
        Node* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    //start clock
        auto start = high_resolution_clock::now();

    Stack myStack;
        myStack.push(8);
        myStack.push(10);
        myStack.push(5);
        myStack.push(11);
        myStack.push(15);
        myStack.push(23);
        myStack.push(6);
        myStack.push(18);
        myStack.push(20);
        myStack.push(17);
        myStack.display();
        myStack.pop();
        myStack.pop();
        myStack.pop();
        myStack.pop();
        myStack.pop();
        myStack.display();
        myStack.push(4);
        myStack.push(30);
        myStack.push(3);
        myStack.push(1);
        myStack.display();

        //stop clock
        auto stop = high_resolution_clock::now();
        //calc time
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "Execution time: " << duration.count() << " ns" << endl;;

    return 0;
}