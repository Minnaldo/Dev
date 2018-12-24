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

    // ! 수정 필요
    // 빈 노드 탐색, 값을 넣을 수 있는 노드 탐색
    // Tree<T> *search(Node<T> *current)
    // {
    //     if (current->left == NULL && current->right == NULL)
    //     {
    //         return current;
    //     }
    //     if (current->left == NULL && current->right != NULL)
    //     {
    //         return current->left;
    //     }
    //     else if(current ->left !=NULL && current->right == NULL)
    //     {
    //         return current->right;
    //     }
    //     else{
    //         search(current->left);
    //     }
    // }

    // 재귀함수 방식으로 전위순회를 한다.
    void inorder(Node<T> *current)
    {
        if (current != NULL)
        {
            inorder(current->left); // 왼쪽 노드를 넣는 이유 : 전위 순회는 왼 - 중 - 우 순으로 순회하기 때문
            visit(current);
            inorder(current->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    Tree<char> tree('A');
    tree.makeNode();
    cout << "inorder >> ";
    tree.inorder(tree.getRoot());
    cout << endl;
    return 0;
}
