#include <iostream>

using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T> *next;

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

template <class T>
class QueueLinkedList {
private:
    Node<T> *front;
    Node<T> *rear;
    int count;

public:
    QueueLinkedList() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    ~QueueLinkedList() {}

    bool isEmpty() {
        return (front == nullptr);
    }


    void enqueue(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    void dequeue() {
        if (!isEmpty()) {
            Node<T> *temp = front;
            front = front->next;
            delete temp;
            count--;
        }
        if (isEmpty()) {
            rear = nullptr;
        }
    }

    T frontElement() {
        if (!isEmpty()) {
            return front->data;
        }
        return T();
    }

    int size() {
        return count;
    }
};

int main() {
    QueueLinkedList<int> myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Front element: " << myQueue.frontElement() << endl;
    cout << "Queue size: " << myQueue.size() << endl;

    myQueue.dequeue();
    cout << "Front element after dequeue: " << myQueue.frontElement() << endl;
    cout << "Queue size after dequeue: " << myQueue.size() << endl;

    myQueue.dequeue();
    myQueue.dequeue();

    cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

