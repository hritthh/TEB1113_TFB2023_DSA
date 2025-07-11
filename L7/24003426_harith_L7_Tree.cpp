/*
id: 24003426
name: harith
group: g2
lab: Queue Array
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void add_root(string name) {
        root = new Node(name);
    }

    void add_left(string parent_name, string child_name) {
        Node* parent = find_node(root, parent_name);
        if (parent) {
            parent->left = new Node(child_name);
        } else {
            cout << "Parent node '" << parent_name << "' not found.\n";
        }
    }

    void add_right(string parent_name, string child_name) {
        Node* parent = find_node(root, parent_name);
        if (parent) {
            parent->right = new Node(child_name);
        } else {
            cout << "Parent node '" << parent_name << "' not found.\n";
        }
    }

    Node* get_node(string name) {
        return find_node(root, name);
    }

    void print_structure() {
        if (!root) {
            cout << "Tree is empty." << endl;
            return;
        }

        cout << "Root: " << root->name << endl;
        if (root->left)
            cout << "Left child of root: " << root->left->name << endl;
        if (root->right)
            cout << "Right child of root: " << root->right->name << endl;

        Node* B = get_node("B");
        if (B && B->left)
            cout << "Left child of B: " << B->left->name << endl;
        if (B && B->right)
            cout << "Right child of B: " << B->right->name << endl;

        Node* C = get_node("C");
        if (C && C->left)
            cout << "Left child of C: " << C->left->name << endl;
        if (C && C->right)
            cout << "Right child of C: " << C->right->name << endl;
    }

public:
    Node* find_node(Node* current, const string& name) {
        if (!current) return nullptr;
        if (current->name == name) return current;
        Node* found = find_node(current->left, name);
        if (found) return found;
        return find_node(current->right, name);
    }
};

int main() {
    Tree tree;

    tree.add_root("A");
    tree.add_left("A", "B");
    tree.add_right("A", "C");
    tree.add_left("B", "D");
    tree.add_right("B", "E");
    tree.add_left("C", "F");
    tree.add_right("C", "G");

    tree.print_structure();

    return 0;
}
