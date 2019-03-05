#include <iostream>
#include <queue>

/**
 *  * 최소 힙 Minimum_Heap
 *  TODO code test
 */

using namespace std;

template <typename T>
class Heap;

template <typename T>
class Node
{
    friend class Heap<T>;

  public:
    Node()
    {
        right = nullptr;
        left = nullptr;
        parent = nullptr;
        data = INT32_MAX;
    }

    Node(T val)
    {
        right = nullptr;
        left = nullptr;
        parent = nullptr;
        data = val;
    }

  private:
    T data;
    Node<T> *right;
    Node<T> *left;
    Node<T> *parent;
};

template <typename T>
class Heap
{
  public:
    Heap()
    {
        root = new Node<T>();
        Count = 0;
    }
    void insert(T val)
    {
        Node<T> *tmp = root;
        Node<T> *parent = tmp->parent;
        Node<T> *newNode = new Node<T>(val);

        while (tmp != nullptr)
        {
            parent = tmp;
            tmp = (tmp->left == nullptr) ? tmp->left : tmp->right;
        }

        tmp = newNode;
        tmp->parent = parent;

        update(tmp); // 최소힙을 만족하기 위해 데이터를 업데이트

        Count++
    }

    void delNode() // 최대 힙에서 삭제연산은 최대 값을 삭제하는 것이다.
    {
        cout << root->data << " has been deleted" << endl;
        Node<T> *last = find_last();
        root->data = last->data;

        Node<t> *tmp = root;

        while (tmp != nullptr)
        {
            if (tmp->data > tmp->left->data)
            {
                swap(tmp->data, tmp->left->data);
                tmp = tmp->left;
            }
            else if (tmp->data > tmp->right->data)
            {
                swap(tmp->data, tmp->right->data);
                tmp = tmp->right;
            }
        }

        Count--;
    }

    Node<T> *find_last()
    {
        Node<T> *last;
        queue<Node<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            Node<T> *current = q.front();

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);

            last = q.back();
            q.pop();
        }
        (last->parent->left == last) ? (last->parent->left = nullptr) : (last->parent->right = nullptr);
        return last;
    }

    void update(Node<T> *current)
    {
        while (current->parent != nullptr) // current 노드가 root 노드가 되면 끝냄
        {
            Node<T> *parent = current->parent;
            if (current->data < parent->data)
            {
                swap(current->data, parent->data);
            }

            current = parent;
        }
    }

    int size()
    {
        return Count;
    }

  private:
    Node<T> *root;
    int Count;

    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}