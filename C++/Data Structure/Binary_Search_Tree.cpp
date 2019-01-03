#include <iostream>
#include <queue>

/** 이진 탐색 트리 참조 (http://jizard.tistory.com/111)
 *  * Node클래스와 Tree클래스를 이용하여 구현
 */

using namespace std;

template <typename T>
class Tree;

template <typename T>
class Node
{
    friend class Tree<T>;

  public:
    Node()
    {
        data = -2000000000;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

  private:
    Node *parent;
    Node *right;
    Node *left;
    T data;
};

template <typename T>
class Tree
{
  private:
    Node<T> *root = new Node<T>();
    Node<T> *head = new Node<T>();

    void visit(Node<T> *current)
    {
        cout << current->data << " ";
    }

    Node<T> *search(Node<T> *current, T data)
    {
        if (current == nullptr)
            return nullptr;
        if (data == current->data)
        {
            return current;
        }
        else if (data < current->data)
        {
            search(current->left, data);
        }
        else
        {
            search(current->right, data);
        }
    }

    // 전위순회 : 중 - 좌 - 우
    //NOTE it is available to implementation with stack
    void preorder(Node<T> *current)
    {
        if (current != nullptr)
        {
            visit(current);
            preorder(current->left);
            preorder(current->right);
        }
    }

    // 중위순회 : 좌 - 중 - 우,
    void inorder(Node<T> *current)
    {
        if (current != nullptr)
        {
            inorder(current->left);
            visit(current);
            inorder(current->right);
        }
    }

    // 후위순회 : 좌 - 우 - 중
    void postorder(Node<T> *current)
    {
        if (current != nullptr)
        {
            postorder(current->left);
            postorder(current->right);
            visit(current);
        }
    }

    // 레벨순회 : BFS로 구현 가능,
    void leveltraversal()
    {
        Node<T> *current;
        queue<Node<T> *> treeQue;
        treeQue.push(root);

        while (!treeQue.empty())
        {
            current = treeQue.front();
            if (current->left != NULL)
            {
                treeQue.push(current->left);
            }
            if (current->right != NULL)
            {
                treeQue.push(current->right);
            }

            cout << treeQue.front()->data << " ";
            treeQue.pop();
        }
    }

  public:
    Tree()
    {
        head->left = root;
        root->parent = head;
    }

    // TODO
    void insertNode(T val)
    {
    }

    void search(T val)
    {
        search(root, val);
    }

    void postOrder()
    {
        postorder(root);
    }

    void preOrder()
    {
        preorder(root);
    }

    void inOrder()
    {
        inorder(root);
    }

    void levelTraversal()
    {
        leveltraversal();
    }
};

int main(int argc, char const *argv[])
{
    Tree<int> *tree = new Tree<int>(); // root값 8로 초기화

    tree->insertNode(8);
    tree->insertNode(10);
    tree->insertNode(7);
    tree->insertNode(5);
    tree->insertNode(11);

    tree->levelTraversal();

    return 0;
}
