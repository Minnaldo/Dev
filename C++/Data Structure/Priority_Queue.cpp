#include <iostream>

using namespace std;

template <typename T>
class PQueue;

template <typename T>
class Node
{
    friend class PQueue<T>;

  public:
    Node()
    {
        this->pre = nullptr;
        this->post = nullptr;
    }
    Node(T val)
    {
        this->pre = nullptr;
        this->post = nullptr;
        this->val = val;
    }
    Node(T val, int priority)
    {
        this->pre = nullptr;
        this->post = nullptr;
        this->val = val;
        this->pri = priority;
    }

  private:
    Node<T> *pre;
    Node<T> *post;
    T val;
    int pri;
};

template <typename T>
class PQueue
{
  private:
    Node<T> *tail;
    Node<T> *head;
    int Size;

    // 우선순위 큐의 우선순위 업데이트
    void update_pri(Node<T> *tmpNode, int priority)
    {
        // tmpNode의 우선순위부터 마지막 tail->pre 노드까지 갱신
        while (tmpNode != tail)
        {
            tmpNode->pri = priority;
            priority++;
            tmpNode = tmpNode->post;
        }
    }

  public:
    PQueue()
    {
        tail = new Node<T>();
        head = new Node<T>();
        Size = 0;
    }

    int size()
    {
        return Size;
    }

    void print_Data()
    {
        Node<T> *tmpNode = head->post;
        if (Size != 0)
        {
            while (tmpNode != tail)
            {
                cout << tmpNode->val << " ";
                tmpNode = tmpNode->post;
            }
            cout << endl;
        }
        else
        {
            cout << "Size is zero" << endl;
        }
    }

    T front()
    {
        return head->post->val;
    }

    T back()
    {
        return tail->pre->val;
    }

    void push(T val)
    {
        Node<T> *newNode = new Node<T>(val, Size + 1);

        if (Size == 0)
        {
            // 큐에 데이터가 없을 때
            head->post = newNode;
            newNode->post = tail;
            newNode->pre = head;
            tail->pre = newNode;
        }

        Node<T> *tmp = tail->pre;
        tmp->post = newNode;
        newNode->post = tail;
        newNode->pre = tmp;
        tail->pre = newNode;

        Size++;
    }

    void insert(T val, int priority)
    {
        Node<T> *tmpNode = head->post;
        Node<T> *newNode = new Node<T>(val, priority);

        while (tmpNode->pri < priority)
        {
            tmpNode = tmpNode->post;
        }

        // tmpNode->pre ==> newNode ==> tmpNode
        newNode->pre = tmpNode->pre;
        tmpNode->pre->post = newNode;
        newNode->post = tmpNode;
        tmpNode->pre = newNode;

        update_pri(tmpNode, priority + 1);

        Size++;
    }

    void pop()
    {
        Node<T> *delNode = head->post;

        head->post = delNode->post;
        head->post->pre = head;

        cout << delNode->val << " has deleted" << endl;
        Size--;
        delete delNode;
        if (Size != 0)
            update_pri(head->post, 1);
    }

    void delete_Pri(int priority)
    {
        Node<T> *tmpNode = head->post;

        while (tmpNode->pri != priority)
        {
            tmpNode = tmpNode->post;
        }

        tmpNode->pre->post = tmpNode->post;
        tmpNode->post->pre = tmpNode->pre;
        Size--;
        update_pri(tmpNode->post, priority);
        delete tmpNode;
    }

    int last()
    {
        return tail->pre->pri;
    }
};

int main(int argc, char const *argv[])
{
    PQueue<int> *pq = new PQueue<int>();

    pq->push(1);
    pq->push(2);
    pq->push(3);

    // pq->print_Data();

    // pq->pop();
    // pq->pop();
    // pq->pop();
    // pq->print_Data();

    pq->insert(10, 2);
    pq->insert(20, 2);
    pq->insert(30, 2);
    pq->print_Data();

    pq->delete_Pri(2);
    pq->print_Data();

    cout << "last pri : " << pq->last() << endl;

    pq->delete_Pri(pq->last());
    pq->print_Data();
    pq->pop();
    pq->print_Data();

    cout << "front : " << pq->front() << " back : " << pq->back() << endl;

    return 0;
}