#include <iostream>

/**
 *  TODO implement the heap structure
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
        data = INT32_MIN;
    }

    Node(T val)
    {
        right = nullptr;
        left = nullptr;
        data = val;
    }

  private:
    T data;
    Node<T> *right;
    Node<T> *left;
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
    void insNode(T val)
    {
        Node<T> *newNode = new Node<T>(val);

        Node<T> *tmp = search(val);

        if (newNode == nullptr)
        {
            newNode->data = val;
        }
        Count++
    }
    void delNode() { Count-- }
    void search(T val)
    {
        search(root, val);
    }

  private:
    Node<T> *root;
    int Count;

    Node<T> *search(Node<T> *tmp, T val)
    {
        if (tmp->data == val)
        {
            return tmp;
        }

        if (val < tmp->data)
        {
            if (tmp->left == nullptr)
                return tmp->left;
            search(tmp->left, val);
        }
        else
        {
            if (tmp->right == nullptr)
                return tmp->right;
            search(tmp->right, val);
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}