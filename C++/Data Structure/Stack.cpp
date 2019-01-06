#include <iostream>

/** stack class
 *  * push, pop, isEmpty, size, stacktoArray function is provided
 */

using namespace std;

template <typename T>
class Stack;

template <typename T>
class Node
{
    friend class Stack<T>;

  public:
    Node()
    {
        data;
        next = nullptr;
    }

  private:
    T data;
    Node *next;
};

template <typename T>
class Stack
{
  public:
    Stack()
    {
        Count = 0;
        top->next = bot;
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
    void pop()
    {
        Node<T> *temp = bot;

        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next->next;
        temp->next = nullptr;
        top->next = temp->next;

        Count--;
    }

    int size()
    {
        return Count;
    }

    T *stacktoArray()
    {
        Node<T> *temp = bot->next;
        int size = Count;
        T *arr = new T[size];

        for (int idx = 0; idx < size; idx++)
        {
            arr[idx] = temp->data;
            temp = temp->next;
        }

        return arr;
    }

    void push(T val)
    {
        Node<T> *temp = bot;
        Node<T> *newNode = new Node<T>();
        newNode->data = val;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        top->next = newNode;
        Count++;
    }

    void printStack()
    {
        Node<T> *temp = bot->next;

        while (temp->next != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << "\n";
    }

  private:
    Node<T> *top = new Node<T>();
    Node<T> *bot = new Node<T>();
    int Count;
};

int main(int argc, char const *argv[])
{
    Stack<int> *stack = new Stack<int>(); // 스택클래스 객체 stacck 생성

    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->push(6);

    stack->printStack(); //프린트

    stack->pop(); // 삭제
    stack->push(10);
    stack->printStack(); //프린트

    int *arr = stack->stacktoArray();

    // 배열 형태 스택 출력
    for (int i = 0; i < stack->size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}