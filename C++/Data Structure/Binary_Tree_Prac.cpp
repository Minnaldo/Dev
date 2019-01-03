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
    Node(T data = -2000000000, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
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
    Node<T> *root;

  public:
    Tree()
    {
        root = new Node<T>();
    }
    Node<T> *getRoot()
    {
        return root;
    }

    // 방문한 노드를 출력하는 함수. REVIEW
    void visit(Node<T> *current)
    {
        cout << current->data << " ";
    }

    T getRootVal()
    {
        return root->data;
    }

    void insertNode(Node<T> *node)
    {
        if (search(root, node->data) == NULL)
        {
            Node<T> *parent = NULL;
            Node<T> *current = root;

            while (current != NULL)
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
    void preorder(Node<T> *current)
    {
        visit(current);
        if (current->left != NULL)
            preorder(current->left);
        if (current->right != NULL)
            preorder(current->right);
    }
    // 중위순회 : 좌 - 중 - 우
    void inorder(Node<T> *current)
    {
        if (current->left == NULL)
        {
            visit(current);
        }
        inorder(current);
        inorder(current);
    }
    // 후위순회 : 좌 - 우 - 중, TODO
    void postorder() {}

    // 레벨순회 : BFS로 구현 가능,
    void levelTraversal(Node<T> *current)
    {
        queue<Node<T> *> treeQue;
        treeQue.push(current);

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
};

int main(int argc, char const *argv[])
{
    Tree<int> tree(8);                 // root값 8로 초기화
    cout << tree.getRoot() << endl;    // root node의 주소값 불러오기
    cout << tree.getRootVal() << endl; // root의 값을 불러오기
    // new Node(value)로 새로운 노드 생성
    tree.insertNode(new Node<int>(9)); // 새로운 node 생성, 타입을 꼭 지정해줘야 함
    tree.search(tree.getRoot(), 9);    // 트리에서 9 값을 찾는 방법, root노드부터 찾아 들어간다, 해당 값을 가지는 노드의 주소 반환

    tree.levelTraversal(tree.getRoot());
    return 0;
}
