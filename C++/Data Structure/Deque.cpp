#include <iostream>

/**
 *  TODO there is no error but, has logical error, I need to modify that
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
        Node<T> *temp = head->back;
        Node<T> *newNode = new Node<T>(val);

        if (temp != nullptr)
        {
            head->back = newNode;
            newNode->back = temp;
            newNode->front = head;
            temp->front = newNode;
        }
        else
        {
            head->back = newNode;
            newNode->front = head;
            newNode->back = tail;
            tail->front = newNode;
        }

        Count++;
    }

    void pop_front()
    {
        Node<T> *temp = head->back;

        if (Count == 0)
        {
            // there is not element
            // delete unavailable
        }
        else
        {
            temp->back->front = head;
            head->back = temp->back;
            delete temp;
            Count--;
        }
    }

    T front()
    {
        return head->back->data;
    }

    void push_back(T val)
    {
        Node<T> *temp = tail->front; // last element
        Node<T> *newNode = new Node<T>(val);

        if (temp != nullptr)
        {
            temp->back = newNode;
            newNode->back = tail;
            newNode->front = temp;
        }
        else
        {
            newNode->front = head;
            newNode->back = tail;
            head->back = newNode;
            tail->front = newNode;
        }

        Count++;
    }

    void pop_back()
    {
        Node<T> *temp = tail->front;

        if (Count == 0)
        {
            // Deque has no element
        }
        else
        {
            temp->front->back = tail;
            tail->front = temp->front;

            delete temp;
            Count--;
        }
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
    cout << "Front : " << deq->front() << "  "
         << " Back : " << deq->back() << "  "
         << "Size : " << deq->size() << endl;

    // push_front의 문제
    deq->push_front(6);
    deq->push_front(5);
    deq->push_front(4);

    deq->print();
    cout << "Front : " << deq->front() << "  "
         << " Back : " << deq->back() << "  "
         << "Size : " << deq->size() << endl;

    deq->pop_back();
    deq->print();

    deq->pop_front();
    deq->print();

    return 0;
}