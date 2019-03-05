#include <iostream>
#include <queue>

/**
 *  * AVL Search Tree ==> 삽입시에 높이차가 2이상 이면 균형을 맞춘다
 *  * 노드의 데이터에 왼쪽 자식노드와 오른쪽 자식노드의 높이차를 저장할 변수 지정
 *  * 왼쪽 자식에 추가 : diff + 1 // 오른쪽 자식에 추가 : diff + (-1)
 */

using namespace std;

template <typename T>
class Tree;

template <typename T>
class Node
{
    friend class Tree<T>;

  public:
    Node(T data = INT32_MIN)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        diff = 0;
    }

  private:
    Node *parent;
    Node *right;
    Node *left;
    T data;
    int diff; // 왼쪽 자식 높이 - 오른쪽 자식 높이
};

template <typename T>
class Tree
{
  private:
    Node<T> *root;
    Node<T> *head = new Node<T>();
    int Count;

    // tmpNode->diff >= 2
    void right_rotate(Node<T> *tmpNode)
    {
        Node<T> *parent = tmpNode->parent;
        Node<T> *child = tmpNode->left; // FIXME

        (parent->data > tmpNode->data ? parent->left : parent->right) = child; // 현재 바꿔야하는 노드의 위치 구하기 / 현재 바꿔야 하는 노드의 위치 = 회전 시 자식노드가 올라올 위치
        child->parent = parent;
        child->right = tmpNode;
        tmpNode->parent = child;
        tmpNode->left = nullptr;
    }

    // tmpNode->diff <= -2
    void left_rotate(Node<T> *tmpNode)
    {
        Node<T> *parent = tmpNode->parent;
        Node<T> *child = tmpNode->right;    // FIXME

        (parent->data > tmpNode->data ? parent->left : parent->right) = child; // 현재 바꿔야하는 노드의 위치 구하기
        child->parent = parent;
        child->left = tmpNode;
        tmpNode->parent = child;
        tmpNode->right = nullptr;
    }

    void visit(Node<T> *current)
    {
        cout << current->data << " ";
    }

    // * ver. recur
    Node<T> *searchRecur(Node<T> *current, T data)
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
    }

  public:
    Tree()
    {
        head->left = root;
        Count = 0;
    }

    void remove(T val)
    {
        Node<T> *delNode = root;
        Node<T> *delParent;

        // 노드 탐색 부분
        while (delNode != nullptr)
        {
            if (delNode->data == val)
            {
                break;
            }
            delParent = delNode;
            delNode = delNode->data > val ? delNode->left : delNode->right;
        }

        if (delNode == nullptr)
        {
            cout << "value is not in the tree" << endl;
            return;
        }

        // 단말 노드일 경우
        if (delNode->left == nullptr && delNode->right == nullptr)
        {
            if (delParent == head) // 부모노드가 head면 삭제하려는 노드는 루트노드
            {
                head->left = nullptr; // head가 root 노드를 가리키는 포인터 변수
                delete root;
            }
            else
            {
                if (delParent->left == delNode)
                {
                    delParent->left = nullptr;
                }
                else
                {
                    delParent->right = nullptr;
                }

                delete delNode;
            }
        }
        // 하나의 서브트리를 가지는 경우
        else if (delNode->right == nullptr || delNode->left == nullptr)
        {
            Node<T> *tmp = (delNode->right == nullptr) ? delNode->left : delNode->right; // 비어있지 않는 자식 노드를 리턴, 그냥 치환을 해버린다.
            // 삭제할 노드가 루트노드 일 때
            if (delParent == head)
            {
                root = tmp;
                root->parent = delParent;
                delParent->left = root;
            }
            else
            {
                // 삭제할 노드가 왼쪽 부모 노드의 왼쪽 노드
                if (delNode == delParent->left)
                {
                    delNode = tmp;
                    delParent->left = delNode;
                    delNode->parent = delParent;
                }
                // 삭제할 노드가 부모 노드의 오른쪽 노드
                else
                {
                    delNode = tmp;
                    delParent->right = delNode;
                    delNode->parent = delParent;
                }
            }
        }
        else
        {
            // 오른쪽 서브트리의 가장 작은값을 가져온다
            Node<T> *tmp = delNode->right;
            Node<T> *tmpParent = delNode;
            while (tmp->left != nullptr)
            {
                tmpParent = tmp;
                tmp = tmp->left;
            }

            tmp->left = delNode->left;
            delNode->left->parent = tmp;
            delNode->left = nullptr;

            tmp->parent = delParent;

            if (delNode == delParent->left)
            {
                delNode = tmp;
                delParent->left = delNode;
                delNode->parent = delParent;
            }
            else
            {
                delNode = tmp;
                delParent->right = delNode;
                delNode->parent = delParent;
            }
        }
        Count--;
    }

    void insert(T val)
    {
        if (search(val))
        {
            cout << val << " is exist in tree" << endl;
            return;
        }

        // tmp 노드에 값이 저장되고 마지막 노드로 들어감
        // tmp 노드에서부터 역으로 올라가며 diff값을 업데이트 한다.
        if (root == nullptr)
        { // insert into root
            root = new Node<T>(val);
            root->parent = head;
        }
        else
        { // insert into another root
            Node<T> *tmp = root;
            Node<T> *tmpParent;

            while (tmp != nullptr)
            {
                tmpParent = tmp;
                tmp = tmp->data > val ? tmp->left : tmp->right;
            }

            tmp = new Node<T>(val);
            tmp->parent = tmpParent;
            (tmpParent->data > val ? tmpParent->left : tmpParent->right) = tmp;

            /* ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ end of insert into tree ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ */

            /* ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ update the diff-value ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
            tmp->diff = 0;
            while (tmpParent != head)
            {
                tmpParent->diff += (tmp == tmpParent->left ? 1 : (-1));

                if (tmpParent->diff >= 2)
                {
                    right_rotate(tmpParent);
                }
                else if (tmpParent->diff <= -2)
                {
                    left_rotate(tmpParent);
                }

                tmpParent = tmpParent->parent;
            }
        }
        Count++;
    }

    // 해당 원소가 있는지 없는지 확인해준다 // loop를 이용하여 구현
    bool search(T val)
    {
        Node<T> *tmp = root;
        Node<T> *parent;

        while (tmp != nullptr)
        {
            if (val == tmp->data)
            {
                return true;
            }
            parent = tmp;
            tmp = tmp->data > val ? tmp->left : tmp->right;
        }

        return false;
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

    // BFS와 구현 방법이 같다
    void levelTraversal()
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

    int size()
    {
        return Count;
    }

    bool isEmpty()
    {
        return Count == 0 ? true : false;
    }

    // 트리를 배열로 변환해주는 함수
    int *treeToArray()
    {
        int *arr = new int[Count + 1];
        int idx = 1;
        Node<T> *current;
        queue<Node<T> *> treeQue;
        treeQue.push(root);

        while (!treeQue.empty())
        {
            current = treeQue.front();
            if (current->left != nullptr)
            {
                treeQue.push(current->left);
            }
            if (current->right != nullptr)
            {
                treeQue.push(current->right);
            }

            arr[idx++] = treeQue.front()->data;
            treeQue.pop();
        }

        return arr;
    }
};

int main(int argc, char const *argv[])
{
    Tree<int> *tree = new Tree<int>(); //  트리 클래스 객체 생성

    tree->insert(8);
    tree->insert(7);
    tree->insert(9);
    tree->insert(1);
    tree->insert(2);
    tree->insert(3);
    tree->insert(11);
    tree->insert(15);
    tree->insert(20);
    tree->insert(10);

    cout << "Level Traversal : ";
    tree->levelTraversal();
    cout << endl;

    cout << "Node Quantity : " << tree->size() << endl;

    int *arrayTree = tree->treeToArray();
    int size = tree->size();

    cout << "Tree Array :: ";
    for (int i = 1; i <= size; i++)
    {
        cout << arrayTree[i] << " ";
    }
    cout << endl;

    tree->remove(30);
    cout << "remove 30 :: ";
    tree->levelTraversal();
    cout << endl;
    tree->remove(20);
    cout << "remove 20 :: ";
    tree->levelTraversal();
    cout << endl;
    tree->remove(1);
    cout << "remove 1 :: ";
    tree->levelTraversal();
    cout << endl;
    return 0;
}
