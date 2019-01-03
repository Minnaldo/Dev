#include <iostream>

/**
 *  * 노드를 삽입할 때, 정렬을 해서 삽입해야??
 *  * 탐색시 절반이 넘어가면, tail에서부터 탐색해 올 수 있음 ==> 성능에 이점
 *  ! 잘못된 구조로 짜여있음 --> 수정 필요
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
        data = -1999999999;
    }

  private:
    T data;
    Node *next;
    Node *prev;
};

template <typename T>
class dLink
{
  public:
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
        newNode->data = val;

        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
            Count++;
        }

        temp->next = newNode->prev;
        newNode->prev = temp->next;
        newNode->next = tail->prev;
    }

    void deleteNode(T val)
    {
        Node<T> *temp = search(val);

        Node<T> *prev = temp->prev;
        Node<T> *nxt = temp->next;

        prev->next = nxt->prev;
        nxt->prev = prev->next;

        Count--;
        delete temp;
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
        Node<T> *temp = head;

        while (temp->next != nullptr) // ! segfault
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
    Node<T> *head = new Node<T>();
    Node<T> *tail = new Node<T>();
    int Count;

    Node<T> *search(T val)
    {
        Node<T> *tmphead = head->next;
        Node<T> *tmptail = tail->prev;

        while (tmphead->data != val && tmptail->data != val)
        {
            tmphead = tmphead->next;
            tmptail = tmptail->prev;
        }

        if (tmphead->data == val)
        {
            return tmphead;
        }
        else
        {
            return tmptail;
        }
    }
};

int main(int argc, char const *argv[])
{
    dLink<int> *dlink = new dLink<int>();

    dlink->insertNode(9);
    dlink->insertNode(10);
    dlink->insertNode(8);
    dlink->insertNode(7);

    dlink->printNode();

    return 0;
}
