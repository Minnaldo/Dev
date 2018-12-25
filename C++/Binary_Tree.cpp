#include <iostream>

using namespace std;

template <typename T>
class Tree;

template <typename T>
class Node
{
    friend class Tree<T>;

  public:
    Node(T data = 0, Node *left = NULL, Node *right = NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }

  private:
    Node *right;
    Node *left;
    T data;
};

template <typename T>
class Tree
{
  private:
    Node<T> *root;

  public:
    Tree(T data = 0)
    {
        root = new Node<T>(data);
    }
    Node<T> *getRoot()
    {
        return root;
    }

    void makeNode()
    {
        root->left = new Tree<T>('B', new Tree<T>('D', new Tree<T>('H')), new Tree<T>('E', new Tree<T>('I'), new Tree<T>('J')));
        root->right = new Tree<T>('C', new Tree<T>('F'), new Tree<T>('G', NULL, new Tree<T>('K')));
    }

    void visit(Node<T> *current) { cout << current->data << " "; }

    TreeNode<T> *getRoot()
    {
        return root;
    }

    T getRootVal()
    {
        return root->data;
    }

    void insertNode(TreeNode<T> *node)
    {
        if (search(root, node->data) == NULL)
        {
            TreeNode<T> *parent = NULL;
            TreeNode<T> *current = root;

            while (current != NULL)
            {
                parent = current;
                if (node->ata < parent->data)
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
                parent->left = node;
            }
            else
            {
                parent->right = node;
            }
            cout << "Inserted " << node->data << endl;
        }
    }

    void visit(TreeNode<T> *current)
    {
        cout << current->data << "  ";
    }

    TreeNode<T> *search(TreeNode<T> *current, T data)
    {
        if (current == NULL)
            return NULL;
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
};

int main(int argc, char const *argv[])
{
    Tree<int> tree(8);                 // root값 8로 초기화
    cout << tree.getRoot() << endl;    // root node의 주소값 불러오기
    cout << tree.getRootVal() << endl; // root의 값을 불러오기
    return 0;
}
