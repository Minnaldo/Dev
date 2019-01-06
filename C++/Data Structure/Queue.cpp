#include <iostream>

using namespace std;

template <typename T>
class Queue;

template <typename T>
class Node
{
    friend class Queue<T>;

  public:
    Node()
    {
        next = nullptr;
        data;
    }

  private:
    Node *next;
    T data;
};

template <typename T>
class Queue
{
  private:
    Node<T> *front = new Node<T>();
    Node<T> *back = new Node<T>();
    int Count;

  public:
    Queue()
    {
        Count = 0;
        front->next = nullptr;
        back->next = nullptr;
    }

    void push_back(T val)
    {
        Node<T> *temp = front;
        Node<T> *newNode = new Node<T>();
        newNode->data = val;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        back->next = newNode;

        if (front->next == temp->next)
        {
            front->next = newNode;
        }

        Count++;
    }

    void pop()
    {
        Node<T> *temp = front->next;
        front->next = temp->next;
        Count--;
        delete temp;
    }

    bool isEmpty()
    {
        if (Count > 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    int size()
    {
        return Count;
    }

    void printQueue()
    {
        Node<T> *temp = front->next;

        while (temp->next != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};

int main(int argc, char const *argv[])
{
    Queue<int> *queue = new Queue<int>();

    queue->push_back(8);
    queue->push_back(2);
    queue->push_back(3);
    queue->push_back(10);
    queue->push_back(16);

    queue->printQueue();

    int size = queue->size();
    cout<<size<<endl;
    return 0;
}