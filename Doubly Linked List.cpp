#include <iostream>
using namespace std;
//doubly link list classs
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << val << " inserted at beginning.\n";
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << val << " inserted at end.\n";
    }

    // Delete a node by value
    void deleteNode(int val) {
        if (head == NULL) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL && temp->data != val)
            temp = temp->next;

        if (temp == NULL) {
            cout << val << " not found in list.\n";
            return;
        }
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next; // deleting head

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
        cout << val << " deleted from list.\n";
    }

    // Search for an element
    void search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << val << " not found in list.\n";
    }

    // Traverse and display
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        cout << "List: NULL <-> ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << " <-> ";
            temp = temp->next;
        }
        cout << " <-> NULL\n";
    }
    //destructor called
    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    DoublyLinkedList obj;

    obj.insertAtEnd(12);//for the search element
    obj.insertAtEnd(17);
    obj.insertAtEnd(06);
    obj.display();

    obj.insertAtBeginning(48);
    obj.display();

    obj.deleteNode(17);
    obj.display();

    obj.deleteNode(5);   // delete head
    obj.display();

    obj.search(12);//12 found in list
    obj.search(99);

    obj.deleteNode(10);
    obj.deleteNode(30);
    obj.display(); // empty list

    return 0;
}