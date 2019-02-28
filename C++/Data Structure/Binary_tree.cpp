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
        root = new Node<T>();
        por = new Node<T>();
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

    void preorder()
    {
        preOrder(por->left);
        cout << endl;
    }
    void inorder()
    {
        inOrder(por->left);
        cout << endl;
    }
    void postorder()
    {
        postOrder(por->left);
        cout << endl;
    }
    void levelTravel()
    {
        lvTraveling(por->left);
        cout << endl;
    }

    Node<T> getRoot()
    {
        return root;
    }

    T getData(int nodeNum)
    {
        queue<Node<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            Node<T> *current = q.front();

            if (current->Num == nodeNum)
            {
                return current->data;
            }

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);

            q.pop();
        }
    }

    T getData(Node<T> *current)
    {
        return current->data;
    }

  private:
    int Count;
    Node<T> *root;
    Node<T> *por;

    void printNode(Node<T> *current) { cout << current->data << " "; }

    void nodeDelete(Node<T> *current, T val, Node<T> *parent)
    {
        if (current->data == val)
        {
            // 오른쪽 자식노드를 부모노드로 하자
            // 리프노드일경우, 중간노드일경우
            if (current->left == nullptr && current->right == nullptr) // when the current node is the leaf node
            {
                if (current->data < parent->data)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;

                delete current;
            }
            else
            {
                // when the current node is not the leaf node
                if (current->left != nullptr && current->right != nullptr)
                {
                    // 둘다 있을 경우
                    Node<T> *tmp = current->right;
                    while (tmp->left != nullptr)
                    {
                        tmp = tmp->left;
                    }

                    tmp->left = current->left;
                    current->left->parent = tmp;

                    if (current->right->data > parent->data)
                    {
                        parent->right = current->right;
                        current->right->parent = parent;
                    }
                    else
                    {
                        parent->left = current->left;
                        current->left->parent = parent;
                    }
                }
                else if (current->left != nullptr && current->right == nullptr)
                {
                    // 왼쪽만 잇을경우
                    if (current->left->data > parent->data)
                    {
                        parent->right = current->left;
                        current->left->parent = parent;
                    }
                    else
                    {
                        parent->left = current->left;
                        current->left->parent = parent;
                    }
                }
                else
                {
                    // 오른쪽 만 있을경우
                    if (current->right->data > parent->data)
                    {
                        parent->right = current->right;
                        current->right->parent = parent;
                    }
                    else
                    {
                        parent->left = current->right;
                        current->right->parent = parent;
                    }
                }

                delete current;
            }
        }

        if (current->data > val)
            nodeDelete(current->left, val, current);
        if (current->data < val)
            nodeDelete(current->right, val, current);
    }

    void nodeInsert(Node<T> *current, T val, Node<T> *parent)
    {
        if (current == nullptr)
        {
            current = new Node<T>(val);
            current->parent = parent;

            if (val < parent->data)
            {
                parent->left = current;
            }
            else
            {
                parent->right = current;
            }
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
    Tree<int> t;
    t.insertNode(1);
    t.insertNode(2);
    t.insertNode(3);
    t.preorder();
    cout << "tree size : " << t.getSize() << endl;
    return 0;
}
