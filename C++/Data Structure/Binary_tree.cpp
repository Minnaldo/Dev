#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class Tree;

template <typename T>
class Node
{
    friend class Tree<T>;

  public:
    Node(T val = 0)
    {
        parent = nullptr;
        right = nullptr;
        left = nullptr;
        data = val;
        Num = 0;
    }

  private:
    Node<T> *parent;
    Node<T> *right;
    Node<T> *left;
    T data;
    int Num;
};

template <typename T>
class Tree
{
  public:
    Tree()
    {
        root = new Node<T>(NULL);
        por = new Node<T>(NULL);
        por->left = root;
        root->parent = por;
        Count = 0;
    }

    void insertNode(T val)
    {
        nodeInsert(por->left, val, por);
        Count++;
    }

    void delNode(T val)
    {
        nodeDelete(por->left, val, por);
        Count--;
    }

    int getSize() { return Count; }

    void preorder() { preOrder(por->left); }
    void inorder() { inOrder(por->left); }
    void postorder() { postOrder(por->left); }
    void levelTravel() { lvTraveling(por->left); }

    void printNode(Node<T> *current) { cout << current->data << " "; }

    Node<T> getRoot()
    {
        return root;
    }

    T getData(int nodeNum)
    {
    }

  private:
    int Count;
    Node<T> *root;
    Node<T> *por;

    void nodeDelete(Node<T> *current, T val, Node<T> *parent)
    {
        if (current->data == val)
        {
            // 오른쪽 자식노드를 부모노드로 하자
            if (current->left != nullptr && current->right != nullptr)
            {

            }
            else if(current->right == nullptr && current->left != nullptr){

            }
            else{

            }
        }

        if (current->data > val)
            nodeDelete(current->left, val, current);
        if (current->data < val)
            nodeDelete(current->right, val, current);
    }

    void nodeInsert(Node<T> *current, T val, Node<T> *parent)
    {
        if (current == NULL)
        {
            current = new Node<T>(val);
            current->parent = parent;
        }
        if (val < current->data)
            nodeInsert(current->left, val, current);
        if (val > current->data)
            nodeInsert(current->right, val, current);
    }

    // 중 -> 좌 -> 우
    void preOrder(Node<T> *current)
    {
        if (current != nullptr)
        {
            printNode(current);
            preOrder(current->left);
            preOrder(current->right);
        }
    }

    // 좌->우->중
    void postOrder(Node<T> *current)
    {
        if (current != nullptr)
        {
            postOrder(current->left);
            postOrder(current->right);
            printNode(current);
        }
    }

    // 좌->중->우
    void inOrder(Node<T> *current)
    {
        if (current != nullptr)
        {
            inOrder(current->left);
            printNode(current);
            inOrder(current->right);
        }
    }

    void lvTraveling(Node<T> *current)
    {
        queue<Node<T> *> q;
        q.push(current);
        while (!q.empty())
        {
            Node<T> *tmpNode = q.front();
            printNode(tmpNode);
            if (tmpNode->left != nullptr)
                q.push(tmpNode->left);
            if (tmpNode->right != nullptr)
                q.push(tmpNode->right);

            q.pop();
        }

        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
