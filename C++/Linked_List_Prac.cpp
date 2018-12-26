#include <iostream>

/**
 *  ! 손볼곳이 많다
 *  * 필요할 때마다 Node를 생성해 데이터를 저장하고 이들을 서로 연결한다.
 *  * 사용의 편의성을 위해 머리와 꼬리르 노드를 따로 갖고 있는다.
 *  TODO
 */

using namespace std;

template <typename T>
class Linked;

template <typename T>
class Node
{

    friend class Linked<T>;

  public:
    Node(T data = 0, Node *next = NULL)
    {
        this->data = data;
        this->next = next;
    }

  private:
    T data;
    Node *next;
    Node *tail;
    Node *head;
};

template <typename T>
class Linked
{
  private:
    Node<T> *head;
    Node<T> *tail;

  public:
    // // 생성자, 객체 생성시 입력된 값을 기준으로 head 노드 생성
    // Linked(T data = 0)
    // {
    //     head = NULL;
    //     tail = head; // 초기 값이 하나일 때에는 head와 tail은 같다.
    // }

    ~Linked() { cout << "Deleted the list " << endl; } //소멸자

    Node<T> *getHead()
    {
        return head;
    }

    void insertNode(T val)
    {
        Node<T> *newNode = new Node<T>(val); // 새로운 노드 객체 생성
        newNode->data = val;     // 데이터 저장
        // newNode->next = NULL;             // 노드의 다음 변수 초기화

        // ! 왜 segment fault가? head에 next가 계속 생성되어있다?
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            // 꼬리를 설정하기 전에 새로운 노드를 먼저 꼬리노드의 다음노드로 선언해야 함
            tail->next = newNode;
        }
        tail = newNode; // 꼬리 노드를 새로 넣은 노드로 지정
    }

    // 노드 삭제    REVIEW  need modify
    void deleteNode(Node<T> *current, T val)
    {
        if (val == current->data)
        {
            return current->next;
        }
        else
        {
            deleteNode(current->next);
        }
    }

    // 노드 전체 출력
    void printList(Node<T> *current)
    {
        cout << current->data << " ";
        if (current->next != NULL)
        {
            printList(current->next);
        }
    }
};

int main(int argc, char const *argv[])
{
    Linked<int> *link;

    link->insertNode(8);
    link->insertNode(7);
    link->insertNode(6);

    link->printList(link->getHead());

    return 0;
}