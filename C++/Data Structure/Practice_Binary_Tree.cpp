#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define null 0

using namespace std;

template <typename T>
class Tree;

template <typename T>
class TreeNode
{
    friend class Tree<T>; // frined : Allow access protected data or function

  private:
    T data;
    TreeNode *left;
    TreeNode *right;

  public:
    TreeNode(T data = 0, TreeNode *left = null, TreeNode *right = null)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <typename T>
class Tree
{
  private:
    TreeNode<T> *root; //Treenode<T> 타입의 root 선언

  public:
    Tree()
    {
        root = new TreeNode<T>();
    }
    void insertNode(TreeNode<T> *node)
    {
        if (search(root, node->data) == null)
        {
            TreeNode<T> *parent = null;
            TreeNode<T> *current = root;

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
                parent->left = node;
            }
            else
            {
                parent->right = node;
            }
            cout << "Inserted " << node->data << endl;
        }
    }

    TreeNode<T> *search(TreeNode<T> *current, T data)
    {
        if (current == null)
            return null;
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

    TreeNode<T> *getRoot()
    {
        return root;
    }

    void inorder(TreeNode<T> *current)
    {
        if (current != null)
        {
            visit(current);
            inorder(current->left);
            inorder(current->right);
        }
    }

    void visit(TreeNode<T> *current)
    {
        cout << current->data << " ";
    }
};

main()
{
    Tree<int> tree;
    vector<int> v;
    srand((unsigned int)time(0));

    //10미만 랜덤수 생성
    for (int i = 0; i < 10; i++)
    {
        int tmp = rand() % 10;
        v.push_back(tmp);
    }

    //랜덤수 트리에 넣기
    for (int i = 0; i < v.size(); i++)
    {
        tree.insertNode(new TreeNode<int>(v.at(i)));
    }

    tree.inorder(tree.getRoot());
    cout << endl;
    tree.visit(tree.getRoot());
    return 0;
}
