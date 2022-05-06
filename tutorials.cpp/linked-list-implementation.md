# Linked LIst implementation.

```cpp
class Node {
public:
    int val = 0;
    Node* next = nullptr;
    Node(int v)
    {
        val = v;
    }

    Node()
    {
        val = 0;
    }

    Node(int v, Node* t)
    {
        val = v;
        next = t;
    }
};

class MyLinkedList {
    int size;
    Node* head;

public:
    MyLinkedList()
    {
        size = 0;
        head = nullptr;
    }

    int get(int index)
    {
        Node* temp = head;
        if (index >= size) {
            return -1;
        }

        while (index--) {
            temp = temp->next;
        }

        return temp->val;
    }

    void addAtHead(int val)
    {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }

    void addAtTail(int val)
    {

        if (head == nullptr) {
            addAtHead(val);
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        temp->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val)
    {

        if (index > size) {
            return;
        }

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        int i = index - 1;

        while (i--) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;

        Node* temp = head;

        if (index == 0) {
            head = head->next;
            delete temp;
            size--;
            return;
        }

        int i = index - 1;

        while (i--)
            temp = temp->next;

        Node* t = temp->next;
        temp->next = t->next;
        delete t;

        size--;
        return;
    }
};
```
