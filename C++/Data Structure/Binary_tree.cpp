#include <iostream>
#include <queue>

/** Binary_Tree :
 *  * 삽입 / 삭제 알고리즘 다시 생각 해보기
 *  * 각 노드별 자식노드 2개와 부모노드를 가리키는 포인터 변수 존재
 *  * 자식노드의 인덱스 = 부모노드 인덱스 * 2 (왼쪽 자식 노드)/ (부모노드 인덱스 *2) +1 (오른쪽 자식 노드)
 */

using namespace std;

template <typename T>
class Tree;

template <typename T>
class Node
{
    friend class Tree<T>;

  public:
    Node(T val = INT32_MIN)
    {
        parent = nullptr;
        right = nullptr;
        left = nullptr;
        data = val;
        Num = 0;
    }

    Node(){
        parent = nullptr;
        right = nullptr;
        left = nullptr;
        data = val;
        Num = 0;
    }

  private:
    Node<T> *parent;
    Node<T> *right;
    Node<T> *left;
    T data;
    int Num;
};

template <typename T>
class Tree
{
  public:
    Tree()
    {
        root = new Node<T>();
        por = new Node<T>();
        por->left = root;
        root->parent = por;
        Count = 0;
    }

    void insertNode(T val)
    {
        nodeInsert(por->left, val, por);
        Count++;
    }

    void delNode(T val)
    {
        nodeDelete(por->left, val, por);
        Count--;
    }

    int getSize() { return Count; }

    void preorder()
    {
        preOrder(por->left);
        cout << endl;
    }
    void inorder()
    {
        inOrder(por->left);
        cout << endl;
    }
    void postorder()
    {
        postOrder(por->left);
        cout << endl;
    }
    void levelTravel()
    {
        lvTraveling(por->left);
        cout << endl;
    }

    Node<T> getRoot()
    {
        return root;
    }

    T getData(int nodeNum)
    {
        queue<Node<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            Node<T> *current = q.front();

            if (current->Num == nodeNum)
            {
                return current->data;
            }

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);

            q.pop();
        }
    }

    T getData(Node<T> *current)
    {
        return current->data;
    }

  private:
    int Count;
    Node<T> *root;
    Node<T> *por;

    void printNode(Node<T> *current) { cout << current->data << " "; }

    // 중 -> 좌 -> 우
    void preOrder(Node<T> *current)
    {
        if (current != nullptr)
        {
            printNode(current);
            preOrder(current->left);
            preOrder(current->right);
        }
    }

    // 좌->우->중
    void postOrder(Node<T> *current)
    {
        if (current != nullptr)
        {
            postOrder(current->left);
            postOrder(current->right);
            printNode(current);
        }
    }

    // 좌->중->우
    void inOrder(Node<T> *current)
    {
        if (current != nullptr)
        {
            inOrder(current->left);
            printNode(current);
            inOrder(current->right);
        }
    }

    void lvTraveling(Node<T> *current)
    {
        queue<Node<T> *> q;
        q.push(current);
        while (!q.empty())
        {
            Node<T> *tmpNode = q.front();
            printNode(tmpNode);
            if (tmpNode->left != nullptr)
                q.push(tmpNode->left);
            if (tmpNode->right != nullptr)
                q.push(tmpNode->right);

            q.pop();
        }

        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    Tree<int> t;
    t.insertNode(1);
    t.insertNode(2);
    t.insertNode(3);
    t.preorder();
    cout << "tree size : " << t.getSize() << endl;
    return 0;
}
