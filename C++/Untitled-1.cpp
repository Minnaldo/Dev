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
    T *parent;
    T *right;
    T *left;
};

template <typename T>
class Tree
{
  private:
    TreeNode<T> *root;

  public:
    //데이터 삽입 함수
    void InsertNode(T data)
    {
        TreeNode<T> cur_node = findEmptyNode(root, data);

        cur_node->data = data;
    }

    //빈 노드를 찾아서 리턴해주는 함수
    TreeNode<T> findEmptyNode(TreeNode<T> cur_node, T data)
    {
        if (cur_node->data == NULL)
        {
            return cur_node;
        }

        if (cur_node->data > data)
        {
            findEmptyNode(cur_node->left, data);
        }
        else if (cur_node->data < data)
        {
            findEmptyNode(cur_node->right, data);
        }
    }

    TreeNode<T> SearchNode(TreeNode<T> cur_node, T input)
    {
        if (cur_node->data == input)
        {
            return cur_node;
        }

        if (cur_node->data > input)
        {
            SearchNode(cur_node->left, input);
        }
        else if (cur_node->data < input)
        {
            SearchNode(cur_node->right, input);
        }
    }

    void DeleteNode(T data)
    {
        TreeNode<T> del_node = SearchNode(root, data);

        if (del_node->left != NULL || del_node->right != NULL)
        {
        }
        else if (del_node->left == NULL && del_node->right == NULL)
        {
            del_node = NULL;
        }
    }

    void preorder(TreeNode<T> cur_node)
    {
        cout<<cur_node->data<<endl;

        if(cur_node->left != NULL)
        {
        }
    }
};

int main(int argc, char const *argv[])
{
    int input;
    char key = '\0';
    while (key != e)
    {
        cout << "종료를 원하면 'e'을 입력해주세요" << endl;
        cin >> key;
        switch (key)
        {
        case e:
            cout << "종료" << endl;
            break;
        case b:
            Tree::preorder(TreeNode::root);
        default:
            cout << "값을 입력해주세요" << endl;
            cin >> input;
            cout << input << " 를 입력합니다" << endl;
        }
    }
    return 0;
}
