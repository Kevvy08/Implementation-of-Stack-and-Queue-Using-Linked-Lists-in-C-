#include <iostream>
using namespace std;

// Node structure for Stack and Queue
struct Node {
    int data;
    Node* next;
};

// Stack implementation
class Stack {
private:
    Node* top;
public:
    Stack() { top = NULL; }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto stack.\n";
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow!\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped " << temp->data << " from stack.\n";
        delete temp;
    }

    void display() {
        Node* temp = top;
        cout << "Stack: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Queue implementation
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() { front = rear = NULL; }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << " into queue.\n";
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow!\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        cout << "Dequeued " << temp->data << " from queue.\n";
        delete temp;
        if (front == NULL) {
            rear = NULL;
        }
    }

    void display() {
        Node* temp = front;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Push to Stack\n";
        cout << "2. Pop from Stack\n";
        cout << "3. Display Stack\n";
        cout << "4. Enqueue to Queue\n";
        cout << "5. Dequeue from Queue\n";
        cout << "6. Display Queue\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 5:
                q.dequeue();
                break;
            case 6:
                q.display();
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}

