#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

#define null 0

using namespace std;

/**
 * * 이진탐색 트리 구현
 * * 이진 탐색 트리 : 각노드에 값이 있다. 노드의 왼쪽 서브트리는 노드보다 작은 값, 오른쪽 서브트리는 노드보다 큰 값
 */

// template <typename T> class TreeNode{
//     friend class tree<T>;
//     private:
//     T data;
// };

template <typename T> class tree
{
  private:
    tree<T>* root;
    T *right;
    T *left;
    int data;
  public:
    tree(T data = 0)
    {
        root = new tree<T>(data);
    }

    tree(T data = 0, T *left = null, T *right = null)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    void insertNode(tree<T> *node)
    {
        if (search(root, node->data) == null)
        {
            tree<T> *parent = null;
            tree<T> *current = root;

            while (current != null)
            {
                parent = current;
                if (node->data < parent->data)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }

            if (node->data < parent->data)
            {
                parent->data = node;
            }
            else
            {
                parent->right = node;
            }

            cout << "Node Inserted" << node->data << endl;
        }
    }

    tree<T> *search(tree<T> *current, T data)
    {
        if (current == null)
            return null;
        if (data == current->data)
        {
            return current;
        }
        else if (data < current->data)  //넣을 값이 현재 노드의 값보다 작을 경우
        {
            search(current->left, data);
        }
        else    //넣을 값이 현재 노드의 값보다 클 경우
        {
            search(current->right, data);
        }
    }

    //TODO DeleteNode 구현
    void deleteNode(tree<T> *node)
    {
        if(search(root, root->data) != null)
        {

        }
    }

    void visit(tree<T> *current){
        cout<< current->data<<endl;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}