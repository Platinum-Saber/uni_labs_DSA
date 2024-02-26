#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

class Stack {
private:
    int max_size;
    int* stack;
    int top;

public:
    Stack(int size) {
        max_size = size;
        stack = new int[max_size];
        top = -1;
    }

    ~Stack() {
        delete[] stack;
    }

    void push(int data) {
        if (isFull()) {
            std::cerr << "Stack Overflow" << std::endl;
            exit(EXIT_FAILURE);
        } 
        else {
            top++;
            stack[top] = data;
        }
    }

    void pop() {
        if (isEmpty()) {
            std::cerr << "Stack Underflow" << std::endl;
            exit(EXIT_FAILURE);
        }
        else {
            top--;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == max_size - 1;
    }

    void stackTop() {
       if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            exit(EXIT_FAILURE);
        }
        else {
            cout << stack[top] << endl;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
        } else {
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    //start clock
        auto start = high_resolution_clock::now();
    
    Stack myStack(10);
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