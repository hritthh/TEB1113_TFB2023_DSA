/*
id: 24003426
name: harith
group: g2
lab: Circular Queue
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // add new node at the end
    void enqueue(string name) {
        Node* new_node = new Node(name);

        if (front == nullptr) {
            front = new_node;
            rear = new_node;
            rear->next_ptr = front;
        } else {
            rear->next_ptr = new_node;
            rear = new_node;
            rear->next_ptr = front;
        }
    }

    void dequeue() {
    if (front == nullptr) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    if (front == rear) {
        // Only one node
        cout << "Dequeued: " << front->name << endl;
        delete front;
        front = nullptr;
        rear = nullptr;
    } else {
        Node* temp = front;
        front = front->next_ptr;
        rear->next_ptr = front;  // maintain circular link
        cout << "Dequeued: " << temp->name << endl;
        delete temp;
    }
}

void display_queue() {
    if (front == nullptr) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* current = front;
    do {
        cout << current->name << " -> ";
        current = current->next_ptr;
    } while (current != front);
    cout << front->name << endl;
}

};

int main() {
    cout << "Queue" << endl;
    Queue queue;

    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alice");
    queue.enqueue("Sarah");

    cout << "Queue: ";
    queue.display_queue();

    queue.dequeue();

    cout << "After dequeueing: " << endl;
    queue.display_queue();

    return 0;
}