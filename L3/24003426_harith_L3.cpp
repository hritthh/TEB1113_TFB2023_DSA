/*
id: 24003426
name: harith
group: g2
lab: L3
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
        }
    }

    void display_list() {
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->name << " ";
            currNode = currNode->next_pointer;
        }
        cout << endl;
    }

    void delete_value(string name) {
        Node* currNode = head;
        Node* prevNode = nullptr;

        while (currNode != nullptr) {
            if (currNode->name == name) {
                if (currNode == head) {
                    head = currNode->next_pointer;
                    delete currNode;
                    return;
                } else {
                    prevNode->next_pointer = currNode->next_pointer;
                    if (currNode == tail) {
                        tail = prevNode;
                    }
                    delete currNode;
                    return;
                }
            }
            prevNode = currNode;
            currNode = currNode->next_pointer;
        }
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

    cout << "Initial list: ";
    std_list.display_list();

    std_list.delete_value("Ahmed");

    cout << "After deletion: ";
    std_list.display_list();

    return 0;
}
