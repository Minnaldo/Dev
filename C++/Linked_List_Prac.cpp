#include <iostream>

/**
 *  ! 손볼곳이 많다
 *  * 필요할 때마다 Node를 생성해 데이터를 저장하고 이들을 서로 연결한다.
 *  * 사용의 편의성을 위해 머리와 꼬리르 노드를 따로 갖고 있는다.
 *  TODO
 */

using namespace std;

// struct Node
// {
//   public:
//     int data;
//     Node *next;
// };

template <typename T>
class Linked;

template <typename T>
class Node
{

    friend class Linked<T>;

  public:
    Node(T val = 0)
    {
        this.data = val;
        next = NULL;
    }

  private:
    T data;
    Node *next;
};

template <typename T>
class Linked
{
  private:
    Node<T> *head = new Node<T>();
    Node<T> *tail = new Node<T>();

    // 노드 전체 출력
    void printAllList(Node<T> *current)
    {
        cout << current->data << " ";
        if (current->next != NULL)
        {
            printAllList(current->next);
        }
    }

  public:
    // 생성자, 객체 생성시 입력된 값을 기준으로 head 노드 생성
    Linked()
    {
        head->next = NULL;
        tail = head->next; // 초기 값이 하나일 때에는 head와 tail은 같다.
    }

    ~Linked() { cout << "Deleted the list " << endl; } //소멸자

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

    void insert(T val)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = val;
        Node<T> *current = search(getHead());

        if (head->next == nullptr)
        {
            head->next = newNode;
        }
        else
        {
            current->next = newNode;
            tail = newNode;
        }
    }

    // 노드 삭제    REVIEW  need modify
    void deleteNode(Node<T> *current, T val)
    {
        if (val == current->next->data)
        {
            delete current->next;
            current->next = current->next->next;
        }
        else
        {
            deleteNode(current->next);
        }
    }

    void printList()
    {
        printAllList(getHead());
    }
};

int main(int argc, char const *argv[])
{
    Linked<int> *link;

    // link->insert(8);
    // link->insertNode(7);
    // link->insertNode(6);

    link->printList();

    return 0;
}