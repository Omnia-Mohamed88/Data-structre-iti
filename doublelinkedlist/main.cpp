#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
    T Data;
    Node<T>* Next;
    Node<T>* Prev;
    Node<T>()
    {
        Data = T();
        Next = Prev = nullptr;
    }
    Node<T>(T d)
    {
        Data = d;
        Next = Prev = nullptr;
    }
    ~Node<T>()
    {
    }
};

template<class T>
class LinkedList
{
private:
    Node<T>* Head;
    Node<T>* Tail;
    int Count;

public:
    LinkedList()
    {
        Head = Tail = nullptr;
        Count = 0;
    }

    LinkedList(const LinkedList& otherList)
    {
        Head = Tail = nullptr;
        Count = 0;
        Node<T>* curr = otherList.Head;
        while (curr != nullptr)
        {
            this->insertLast(curr->Data);
            curr = curr->Next;
        }
    }

    void insertLast(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty())
        {
            Head = Tail = newNode;
        }
        else
        {
            newNode->Prev = Tail;
            Tail->Next = newNode;
            Tail = newNode;
        }
        Count += 1;
    }

    void insertFirst(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty())
        {
            Head = Tail = newNode;
        }
        else
        {
            newNode->Next = Head;
            Head->Prev = newNode;
            Head = newNode;
        }

        Count += 1;
    }

    void insertAt(T data, int pos)
    {
        if (pos == 0)
        {
            insertFirst(data);
        }
        else if (pos == Count)
        {
            insertLast(data);
        }
        else
        {
            Node<T>* curr = Head;
            Node<T>* newNode = new Node<T>(data);
            for (int i = 1; i < pos; i++)
            {
                curr = curr->Next;
            }

            newNode->Next = curr->Next;
            newNode->Prev = curr;
            curr->Next->Prev = newNode;
            curr->Next = newNode;
            Count += 1;
        }
    }

    void Display()
    {
        if (isEmpty())
        {
            cout << "Empty";
        }
        else
        {
            Node<T>* curr = Head;
            while (curr != nullptr)
            {
                cout << curr->Data << " ";
                curr = curr->Next;
            }
        }

        cout << endl;
    }

    void reverse_Display()
    {
        if (isEmpty())
        {
            cout << "Empty";
        }
        else
        {
            Node<T>* curr = Tail;
            while (curr != nullptr)
            {
                cout << curr->Data << " ";
                curr = curr->Prev;
            }
        }

        cout << endl;
    }

    bool isEmpty()
    {
        return Count == 0;
    }

    void ClearList()
    {
        Node<T>* temp;
        while (Head != nullptr)
        {
            temp = Head;
            Head = Head->Next;
            delete temp;
        }
        Tail = nullptr;
        Count = 0;
    }

    Node<T>* Search(T data)
    {
        Node<T>* curr = Head;
        while (curr != nullptr)
        {
            if (curr->Data == data)
            {
                return curr;
            }
            else
            {
                curr = curr->Next;
            }
        }
        return nullptr;
    }

    void Delete(T data)
    {
        Node<T>* newNode = Search(data);
        if (newNode != nullptr)
        {
            if (Count == 1)
            {
                Head = Tail = nullptr;
                delete newNode;
            }
            else if (Head->Data == data)
            {
                DeleteFirst();
            }
            else if (Tail->Data == data)
            {
                DeleteLast();
            }
            else
            {
                Node<T>* curr = Head;
                while (curr->Data != newNode->Data)
                {
                    curr = curr->Next;
                }
                curr->Prev->Next = curr->Next;
                curr->Next->Prev = curr->Prev;
                delete curr;
                Count -= 1;
            }
        }
        else
        {
            cout << "Not Exist";
        }
    }

    void DeleteFirst()
    {
        if (Count == 0)
            cout << "Empty List" << endl;
        else if (Count == 1)
        {
            delete Head;
            Head = Tail = nullptr;
        }
        else
        {
            Node<T>* temp = Head;
            Head = Head->Next;
            Head->Prev = nullptr;
            delete temp;
        }
        Count--;
    }

    void DeleteLast()
    {
        if (Count == 0)
            cout << "Empty List" << endl;
        else if (Count == 1)
        {
            delete Head;
            Head = Tail = nullptr;
        }
        else
        {
            Node<T>* temp = Tail;
            Tail->Prev->Next = nullptr;
            Tail = Tail->Prev;
            delete temp;
        }
        Count--;
    }

    void BubbleSort()
    {
        bool flag;
        Node<T>* last = nullptr;

        do
        {
            flag = false;
            Node<T>* curr = Head;

            while (curr != last && curr->Next != nullptr)
            {
                if (curr->Data > curr->Next->Data)
                {
                    T temp = curr->Data;
                    curr->Data = curr->Next->Data;
                    curr->Next->Data = temp;
                    flag = true;
                }
                curr = curr->Next;
            }
            last = curr;

        } while (flag);
    }

    ~LinkedList()
    {
        // Implement destruction of nodes if needed
    }
};

int main()
{
    LinkedList<int> myList;

    myList.insertLast(50);
    myList.insertLast(40);
    myList.insertLast(30);

    cout << "before insert first: ";
    myList.Display();

    myList.insertFirst(5);
    cout << "after insert first: ";
    myList.Display();

    myList.insertAt(15, 2);
    cout << "after insert at pos 2: ";
    myList.Display();

    cout << "display list: ";
    myList.Display();

    cout << "reverse display list ";
    myList.reverse_Display();

    LinkedList<int> copiedList(myList);

    cout << "The copied linked list: ";
    copiedList.Display();

    int dataToDelete = 20;
    cout << "deleting " << dataToDelete << " from the list: ";
    myList.Delete(dataToDelete);
    myList.Display();

    cout << "deleting the first element: ";
    myList.DeleteFirst();
    myList.Display();

    cout << "deleting the last element: ";
    myList.DeleteLast();
    myList.Display();

    cout << "before apply bubbleSort: ";
    myList.Display();
    myList.BubbleSort();
    cout << "after apply BubbleSort: ";
    myList.Display();

    return 0;
}


