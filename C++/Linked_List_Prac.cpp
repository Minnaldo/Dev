#include <iostream>

/**
 *  ! 손볼곳이 많다
 *  * 필요할 때마다 Node를 생성해 데이터를 저장하고 이들을 서로 연결한다.
 *  * Good_Notes -> 낙서 p.27
 *  TODO
 */

using namespace std;

template <typename T>
class Link;

template <typename T>
class Node
{
    friend class Link<T>;

    Node()
    {
        next = NULL;
        data = -1; // 기본 초기화 값
    }

  private:
    T data;
    Node *next;
};

template <typename T>
class Link
{
  public:
    void print()
    {
        printNode(getHead());
    }

    bool isEmpty()
    {
        if (getHead()->next == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Node<T> *getHead()
    {
        return this->head;
    }

    Node<T> *search(Node<T> *current)
    {
        if (current->next == NULL)
        {
            return current;
        }

        search(current->next);
    }

    int size()
    {
        Count = 0;
        Node<T> *temp = getHead()->next;

        while (temp->next != NULL)
        {
            temp = temp->next;
            Count++;
        }
    }

  private:
    Node<T> *haed = new Node<T>();
    Node<T> *tail = new Node<T>();
    int Count;

    void printNode(Node<T> *current)
    {
        cout << current->data << " ";
        if (current->next != NULL)
        {
            printNode(current->next);
        }
    }

    void insertNode(T data)
    {
        Node<T> *temp = getHead()->next; // temp : 제일 첫번째 값이 들어가있는 노드

        //  다음을 가리키는 포인터가 비어있는 노드를 반복문을 돌며 찾는다
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        Node<T> *newNode = new Node<T>();
        newNode->data = data;
        temp->next = newNode;
        tail->next = newNode;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}