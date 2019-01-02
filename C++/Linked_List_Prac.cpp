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
        next = nullptr;
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
    void printNode()
    {
        print(head->next);
        cout<<endl;
    }

    bool isEmpty()
    {
        if (head->next == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Node<T> *search(Node<T> *current)
    {
        if (current->next == nullptr)
        {
            return current;
        }

        search(current->next);
    }

    void insert(T val)
    {
        insertNode(val);
    }

    int size()
    {
        Count = 0;
        Node<T> *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
            Count++;
        }
        return Count;
    }

    Link()
    {
        head->next = nullptr;
        tail->next = nullptr;
    }

    // TODO check this to exactly active
    ~Link()
    {
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            Node<T> *temp1 = temp->next;
            delete temp;
            temp = temp1->next;
        }
        delete tail;
    }

  private:

    Node<T> *head = new Node<T>();
    Node<T> *tail = new Node<T>();
    int Count;

    void print(Node<T> *current)
    {
        cout << current->data << " ";
        if (current->next != nullptr)
        {
            print(current->next);
        }
    }

    void insertNode(T data)
    {
        // Node<T> *temp = getHead()->next; // temp : 제일 첫번째 값이 들어가있는 노드
        Node<T> *temp = head;

        //  다음을 가리키는 포인터가 비어있는 노드를 반복문을 돌며 찾는다
        while (temp->next != nullptr)
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
    Link<int> *link = new Link<int>();

    link->insert(8);
    link->insert(9);
    link->insert(10);

    cout << "Value in List : ";
    link->printNode();

    cout << "List Size : " << link->size() << endl;
    link->isEmpty();

    return 0;
}