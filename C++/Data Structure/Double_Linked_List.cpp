#include <iostream>

/**
 *  * 노드를 삽입할 때, 정렬을 해서 삽입해야??
 *  * 탐색시 절반이 넘어가면, tail에서부터 탐색해 올 수 있음 ==> 성능에 이점
 *  * 각 노드에 인덱스 삽입? REVIEW
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

    // 리스트 뒤쪽 끝단에 노드 삽입
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
            newNode->next = tail;
            newNode->prev = temp;
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
    }

    // 리스트 중간에 노드 삽입
    void insertNode(T preVal, T nxtVal, T val)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = val;

        Node<T> *tempH = search(preVal);
        Node<T> *tempT = search(nxtVal);

        tempH->next = newNode;
        newNode->prev = tempH;
        tempT->prev = newNode;
        newNode->next = tempT;
        Count++;
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
        Node<T> *temp = head->next; // 주소복사라서 같은 값을 가리킨다.
        cout << "List : "
             << "[ ";
        while (temp->next != tail)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << temp->data << " ]" << endl;
    }

    int size()
    {
        return Count;
    }

    Node<T>* getHead()
    {
        return head;
    }

    Node<T>* getTail()
    {
        return tail;
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

    dlink->insertNode(8, 7, 11);    // 중간 삽입
    dlink->printNode();

    dlink->deleteNode(8);   // 중간 삭제
    dlink->printNode();

    dlink->deleteNode(9);   // 처음 삭제
    dlink->printNode();

    dlink->deleteNode(7);   // 마지막 삭제
    dlink->printNode();
    return 0;
}
