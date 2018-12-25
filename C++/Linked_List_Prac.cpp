#include <iostream>

/**
 *  ! 손볼곳이 많다
 */

using namespace std;

template <typename T>
class Linked
{
    Linked<T>(T data = 0)
    {
        haed = new Linked<T>(val);  //생성자
    }
    void insertNode(T val)
    {
        newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL)
        {
            haed = newNode;
        }
        else
        {
            tail->next = newNode;
        }
        tail = newNode; // 꼬리 노드를 새로 넣은 노드로 지정
    }

    void deleteNode(Linked *current, T val)
    {
        if (val == current->data)
        {
            return current->next;
        }
        else
        {
            deleteNode(current->next);
        }
    }

  private:
    T data;
    Linked *next;
    Linked *head;
    Linked *tail;
};

int main(int argc, char const *argv[])
{
    int readData;
    Linked<int> link(8);

    return 0;
}