#include <iostream>

/**
 *  * DEQUE implementation
 *  @param push_front / push_back / pop_front / pop_back / size / print / front / back
 */

using namespace std;

template <typename T>
class Deque;

template <typename T>
class Node
{
    friend class Deque<T>;

  public:
    Node(T data = 0)
    {
        front = nullptr;
        back = nullptr;
        this->data = data;
    }

  private:
    T data;
    Node *front;
    Node *back;
};

template <typename T>
class Deque
{
  public:
    Deque() // 생성자
    {
        head = new Node<T>();
        tail = new Node<T>();
        Count = 0;
    }

    void push_front(T val)
    {
        Node<T> *temp = head;
        Node<T> *newNode = new Node<T>();
        newNode->data = val;

        // if (head->back != nullptr)
        if (temp->back != nullptr)
        {
            temp->back->front = newNode;
            temp->back = newNode;
            newNode->front = temp;
        }
        else
        {
            head->back = newNode;
            tail->front = newNode;
            newNode->front = head;
            newNode->back = tail;
        }

        Count++;
    }

    void pop_front()
    {
        Node<T> *temp = head->back;
        T val = temp->data;
        head->back = temp->back;
        temp->back->front = head;

        delete temp;

        Count--;

        cout << "\'" << val << "\' : deleted\n";
    }

    T front()
    {
        return head->back->data;
    }

    void push_back(T val)
    {
        Node<T> *temp = tail;
        Node<T> *newNode = new Node<T>();
        newNode->data = val;

        if (temp->front != nullptr)
        // if(Count != 0)
        {
            temp->front->back = newNode;
            temp->front = newNode;
            newNode->back = temp;
        }
        else // Count = 0, 비어있는 상태
        {
            head->back = newNode;
            temp->front = newNode;
            newNode->back = tail;
            newNode->front = head;
        }

        Count++;
    }

    // TODO need modify
    void pop_back()
    {
        Node<T> *temp = tail->front;
        T val = temp->data;
        tail->front = temp->front;
        temp->front->back = tail;

        delete temp;

        Count--;

        cout << "\'" << val << "\' : deleted\n";
    }

    T back()
    {
        return tail->front->data;
    }

    void print()
    {
        Node<T> *temp = head->back;
        while (temp->back != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->back;
        }

        cout << endl;
    }

    int size()
    {
        return Count;
    }

  private:
    int Count;
    Node<T> *head;
    Node<T> *tail;
};

int main(int argc, char const *argv[])
{
    Deque<int> *deq = new Deque<int>();
    deq->push_back(1);
    deq->push_back(2);
    deq->push_back(3);

    deq->print();
    cout << "Size : " << deq->size() << endl;
    cout << "Front : " << deq->front() << "  "
         << " Back : " << deq->back() << endl;

    // deq->push_front(6);
    // deq->push_front(5);
    // deq->push_front(4);

    // cout << "Front : " << deq->front() << "  "
    //      << " Back : " << deq->back() << endl;

    // deq->print(); // ? 뭐지? push_front에 문제?
    // cout << "Size : " << deq->size() << endl;

    // deq->pop_back();

    return 0;
}