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
        data = -2000000000;
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
        head->next = tail;
        tail->prev = head;
    }

    //TODO need difference perspective
    // ! 여기서 문제
    void insertNode(T val)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = val;
        Count++;

        Node<T> *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        if (temp == head)
        {
            // 가장 첫번째 노드, 현재 리스트가 비어있는 상태
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = tail;
            tail->prev = newNode;
        }
        else if (temp == tail->prev)
        {
            // 가장 마지막 노드
            temp->next = newNode;
            newNode->next = tail;
            newNode->prev = temp;
            tail->prev = newNode;
        }
        else
        {
            // 중간 노드, TODO
        }
    }

    void deleteNode(T val)
    {
        Node<T> *temp = search(val);

        Node<T> *prev = temp->prev;
        Node<T> *nxt = temp->next;

        prev->next = nxt;
        nxt->prev = prev;

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
        Node<T> *temp = head; // 주소복사라서 같은 값을 가리킨다.

        while (temp->next != tail)
        {
            cout << temp->data << " ";
        }
        // cout << temp->data << endl;
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
