/*
id: 24003426
name: harith
group: g2
lab: L4 Circular
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_pointer;

    Node(string name) {
        this->name = name;
        this->next_pointer = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_item(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next_pointer = node;
            tail = node;
             tail->next_pointer = head;
        }
    }

    void display_list() {
    if (head == nullptr) return;

    Node* currNode = head;
    
    do {
        cout << currNode->name << "->";
        currNode = currNode->next_pointer;

        } while (currNode!=head);

    cout << currNode->name << endl;
}


};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alice");

    LinkedList std_list;

    std_list.add_item(node1);
    std_list.add_item(node2);
    std_list.add_item(node3);

    cout << "List: ";
    std_list.display_list();

    return 0;
}