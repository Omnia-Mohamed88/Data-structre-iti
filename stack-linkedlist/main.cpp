#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node() {
        data = T();
        next = nullptr;
    }

    Node(T data) {
        this->data = data;
        next = nullptr;
    }

    ~Node() {}
};

template<class T>
class StackLinkedList {
private:
    Node<T>* top;
    int count;

public:

    StackLinkedList() {
        top = nullptr;
        count = 0;
    }

    StackLinkedList(const StackLinkedList<T>& other) {
        top = nullptr;
        count = 0;

        Node<T>* current = other.top;
        while (current != nullptr) {
            append(current->data);
            current = current->next;
        }
    }

    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = top;
        top = newNode;
        count++;
    }

    T pop() {
        if (!isEmpty()) {
            Node<T>* temp = top;
            T poppedData = temp->data;
            top = top->next;
            delete temp;
            count--;
            return poppedData;
        }

        return T();
    }

    void display() {
        Node<T>* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }


    void append(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (top == nullptr) {
            top = newNode;
        } else {
            Node<T>* current = top;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        count++;
    }
};

int main() {
    StackLinkedList<int> originalStack;
    originalStack.push(10);
    originalStack.push(20);
    originalStack.push(30);

    cout << "Original Stack: ";
    originalStack.display();

    StackLinkedList<int> copiedStack(originalStack);

    cout << "Copied Stack: ";
    copiedStack.display();

    cout << "Popped element from copied stack: " << copiedStack.pop() << endl;

    return 0;
}


