/*
id: 24003426
name: harith
group: g2
lab: L3 doubly circular
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_pointer;
    Node* prev_pointer;

    // Constructor to initialize the node
    Node(string name) {
        this->name = name;
        this->next_pointer = nullptr;
        this->prev_pointer = nullptr;
    }
};

class DoublyCircularLinkedList {
public:
    Node* head;
    Node* tail;

    // Constructor to initialize the list
    DoublyCircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to add a node to the list
    void add_item(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
            head->next_pointer = head; // Point head to itself
            head->prev_pointer = head; // Point head to itself
        } else {
            tail->next_pointer = node;
            node->prev_pointer = tail;
            node->next_pointer = head;
            head->prev_pointer = node;
            tail = node;
        }
    }

    // Function to display the list forward (from head to tail)
    void display_list() {
        if (head == nullptr) return;

        Node* currNode = head;
        cout << "List Forward: ";
        do {
            cout << currNode->name;
            currNode = currNode->next_pointer;
            if (currNode != head) cout << " ";
        } while (currNode != head);

        cout << endl; // End the line after printing the list
    }

    // Function to display the list backward (from tail to head)
    void display_list_backward() {
        if (head == nullptr) return;

        Node* currNode = tail;
        cout << "List Backward: ";
        do {
            cout << currNode->name;
            currNode = currNode->prev_pointer;
            if (currNode != tail) cout << " ";
        } while (currNode != tail);

        cout << endl; // End the line after printing the list
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alice");

    DoublyCircularLinkedList std_list;

    std_list.add_item(node1);
    std_list.add_item(node2);
    std_list.add_item(node3);

    std_list.display_list();           // Print list forward
    std_list.display_list_backward();  // Print list backward

    return 0;
}
