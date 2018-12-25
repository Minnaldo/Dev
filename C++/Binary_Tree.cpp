#include <iostream>

/** 이진 탐색 트리 참조 (http://jizard.tistory.com/111)
 *  * Node클래스와 Tree클래스를 이용하여 구현
 *  * Node 클래스는 Tree클래스의 friend 클래스
 *  * Tree 클래스의 생성자로 root노드 초기화, 초기값을 받지 않으면 0으로 초기화한다
 */

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

    void visit(Node<T> *current) { cout << current->data << " "; }

    Node<T> *getRoot()
    {
        return root;
    }

    T getRootVal()
    {
        return root->data;
    }

    void insertNode(Node<T> *node)
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

    void visit(Node<T> *current)
    {
        cout << current->data << "  ";
    }

    Node<T> *search(Node<T> *current, T data)
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

    // 전위순회 : 중 - 좌 - 우
    void preorder(){}
    // 중위순회 : 좌 - 중 - 우
    void inorder(){}
    // 후위순회 : 좌 - 우 - 중
    void postorder(){}
    // 레벨순회 : BFS로 구현 가능,
};

int main(int argc, char const *argv[])
{
    Tree<int> tree(8);                 // root값 8로 초기화
    cout << tree.getRoot() << endl;    // root node의 주소값 불러오기
    cout << tree.getRootVal() << endl; // root의 값을 불러오기
    // new Node(value)로 새로운 노드 생성
    tree.insertNode(new Node(9)); // 새로운 node 생성
    tree.search(tree.getRoot(), 9);    // 트리에서 9 값을 찾는 방법, root노드부터 찾아 들어간다, 해당 값을 가지는 노드의 주소 반환
    return 0;
}
