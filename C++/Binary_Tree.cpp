#include <iostream>

using namespace std;

template <typename T>
class Tree;

template <typename T>
class TreeNode
{
    friend class Tree<T>;

  public:
    TreeNode(T data = 0, TreeNode *left = NULL, TreeNode *right = NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }

  private:
    T data;
    TreeNode *left;
    TreeNode *right;
};

//typedef <typename T> class Tree{};
template <typename T>
class Tree
{
  private:
    TreeNode<T> *root;

  public:
    Tree(T data = 0)
    {
        root = new TreeNode<T>(data);
    }

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
