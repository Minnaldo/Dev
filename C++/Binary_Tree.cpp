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

    void buildTree()
    {
        root->left = new TreeNode<T>('B', new TreeNode<T>('D', new TreeNode<T>('H')), new TreeNode<T>('E', new TreeNode<T>('I'), new TreeNode<T>('J')));
        root->right = new TreeNode<T>('C', new TreeNode<T>('F'), new TreeNode<T>('G', null, new TreeNode<T>('K')));
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
