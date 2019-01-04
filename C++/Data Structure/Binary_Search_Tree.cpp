#include <iostream>
#include <queue>

/** 이진 탐색 트리 참조 (http://jizard.tistory.com/111)
 *  * 이진 탐색트리는 삽입하려는 값과 현재 노드의 값을 비교하여 노드를 추가하여 삽입하여야 한다.
 *  * root노드의 값을 무엇으로 설정할 것인가??
 */

using namespace std;

template <typename T>
class Tree;

template <typename T>
class Node
{
    friend class Tree<T>;

  public:
    Node(T data = -2000000000)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
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
    Node<T> *root = new Node<T>();
    Node<T> *head = new Node<T>();
    int Count;

    void visit(Node<T> *current)
    {
        cout << current->data << " ";
    }

    Node<T> *search(Node<T> *current, T data)
    {
        if (current == nullptr)
            return nullptr;
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
    //NOTE it is available to implementation with stack
    void preorder(Node<T> *current)
    {
        if (current != nullptr)
        {
            &visit(current);
            preorder(current->left);
            preorder(current->right);
        }
    }

    // 중위순회 : 좌 - 중 - 우,
    void inorder(Node<T> *current)
    {
        if (current != nullptr)
        {
            inorder(current->left);
            &visit(current);
            inorder(current->right);
        }
    }

    // 후위순회 : 좌 - 우 - 중
    void postorder(Node<T> *current)
    {
        if (current != nullptr)
        {
            postorder(current->left);
            postorder(current->right);
            &visit(current);
        }
    }

    // 레벨순회 : BFS로 구현 가능,
    void leveltraversal()
    {
        Node<T> *current;
        queue<Node<T> *> treeQue;
        treeQue.push(root);

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

            visit(treeQue.front());
            treeQue.pop();
        }
    }

    void ToArray()
    {
        int *arr = new int[Count + 1];
        int idx = 1;
        Node<T> *current;
        queue<Node<T> *> treeQue;
        treeQue.push(root);

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

            arr[idx++] = treeQue.front()->data;
            treeQue.pop();
        }
    }

  public:
    Tree()
    {
        head->left = root;
        root->parent = head;
        Count = 0;
    }

    // FIXME can't input value in root node
    void insertNode(T val)
    {
        Node<T> *temp = root;
        Node<T> *newNode = new Node<T>();
        newNode->data = val;

        while (true)
        {
            if (temp->data > val)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    newNode->parent = temp;
                    cout << "Inserted : " << newNode->data << endl;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (temp->data < val)
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    newNode->parent = temp;
                    cout << "Inserted : " << newNode->data << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        Count++;
    }

    void search(T val)
    {
        search(root, val);
    }

    void postOrder()
    {
        postorder(root);
    }

    void preOrder()
    {
        preorder(root);
    }

    void inOrder()
    {
        inorder(root);
    }

    void levelTraversal()
    {
        leveltraversal();
    }

    int getNodeCount()
    {
        return Count;
    }

    int *bTreeToArray()
    {
        ToArray();
    }
};

int main(int argc, char const *argv[])
{
    Tree<int> *tree = new Tree<int>();  //  트리 클래스 객체 생성

    tree->insertNode(8);
    tree->insertNode(10);
    tree->insertNode(7);
    tree->insertNode(5);
    tree->insertNode(11);

    cout << "Level Traversal : ";
    tree->levelTraversal();
    cout << endl;

    cout << "Node Quantity : " << tree->getNodeCount() << endl;

    int *arrayTree = tree->bTreeToArray();

    int size = (sizeof(arrayTree) / sizeof(arrayTree[0])) ;

    for (int i = 1; i <= size; i++)
    {
        cout << arrayTree[i] << " ";
    }
    cout << endl;

    return 0;
}
