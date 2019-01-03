#include <iostream>

/**
 *  * 노드를 삽입할 때, 정렬을 해서 삽입해야??
 *  * 탐색시 절반이 넘어가면, tail에서부터 탐색해 올 수 있음 ==> 성능에 이점
 */

using namespace std;

template <typename T>
class dLink;

template <typename T>
class Node
{
    friend class dLink<T>;

    Node()
    {
        next = nullptr;
        prev = nullptr;
        data = -1;
    }

  private:
    T data;
    Node *next;
    Node *prev;
};

template <typename T>
class dLink
{
    dLink() // 생성자
    {
        head->prev = nullptr;
        tail->next = nullptr;
        head->next = tail->prev;
        tail->prev = head->next;
    }

    //TODO need difference perspective
    void insertNode(T val)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = data;

        Node<T> *temp = haed;
        while (temp->next != nullptr)
        {
            temp = temp->next;
            Count++;
        }

        temp->next = newNode->prev;
        newNode->prev = temp->next;
        newNode->next = nullptr;
    }

    void deleteNode(T val)
    {
    }

    void search(T val)
    {
        Node<T> *tmphead = head->next;
        Node<T> *tmptail = tail->prev;

        while (tmphead->data != val && tmptail->data != val)
        {
            tmphead = tmphead->next;
            tmptail = tmptail->prev;
        }
        // TODO 추가필요
    }

    bool isEmpty()
    {
        if (head->next == tail->prev)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void printNode()
    {
        Node<T> *temp = head->next;

        while (temp->next != nullptr)
        {
            cout << temp->data << " ";
        }
        cout << temp->data << endl;
    }

    int size()
    {
        return Count;
    }

  private:
    Node<T> *haed = new Node<T>();
    Node<T> *tail = new Node<T>();
    int Count;
};

int main(int argc, char const *argv[])
{
    dLink<int> *link = new dLink<int>();
    return 0;
}
