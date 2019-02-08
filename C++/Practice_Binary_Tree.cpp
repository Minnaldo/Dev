#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define null 0

using namespace std;

/**
 * * 이진탐색 트리 구현
 * * 이진 탐색 트리 : 각노드에 값이 있다. 노드의 왼쪽 서브트리는 노드보다 작은 값, 오른쪽 서브트리는 노드보다 큰 값
 */

template <typename T>
class avlTree;

template <typename T>
class Node
{
    friend class avlTree<T>;

  private:
    T data;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;

  public:
    // constructor of the Node class
    Node(T val = 0)
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        data = val;
    }
};

template <typename T>
class avlTree
{
  private:
    Node<T> *root;
    int Count;

  public:
    avlTree()
    {
        root = new Node<T>();
        Count = 0;
    }

    void insert(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        Node<T> *temp = root;

        while (true)
        {
            if(temp->left == nullptr)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }

        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}