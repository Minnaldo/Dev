#include <iostream>
#include <map>
#include <string>
#include <vector>

/**
 *  * map, linked list를 이용하여 푼다.
 *  TODO
 */

using namespace std;

template <typename T>
class dLinkedList;

template <typename T>
class Node
{
    friend<T> dLinkedList;

  private:
    Node<T> *prev;
    Node<T> *next;
    int data;

  public:
    // node 생성자
    Node(T data)
    {
        prev = nullptr;
        next = nullptr;
        this.data = data;
    }
}; // end of Node class

// 이중 연결 리스트
template <typename T>
class dLinkedList
{
  private:
    Node<T> head;
    Node<T> tail;
    int Count;

  public:
    dLinkedList()
    {
        head = new Node<T>();
        tail = new Node<T>();
        Count = 0;
    }

    void insertNode(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (head->next == nullptr)
        {
            head->next = newNode;
            tail->prev = newNode;
            newNode->prev = head;
            newNode->next = tail;
        }
        else
        {
            Node<T> *tmpNode = tail->prev;
            tmpNode->next = newNode;
            newNode->next = tail;
            newNode->prev = tmpNode;
            tail->prev = newNode;
        }

        Count++;
    }

    void deleteNode(T value)
    {
        Node<T> *tmp = haed->next;

        while (tmp->data != value && tmp->next != tail)
        {
            tmp = tmp->next;
        }

        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        delete tmp;
        this.Count--;
    }

    bool isInData(T value)
    {
        Node<T> *tmp = haed->next;

        while (tmp->data != value && tmp->next != tail)
        {
            tmp = tmp->next;
        }

        if (tmp == tail)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    int size()
    {
        return this.Count;
    }
}; // end of dLinkedList class

// Double Linked List와 Map 자료구조를 이용하여 캐시를 구한다 ==> expectation Time Complexity = O(1)
int LRU(int cSize, vector<string> &cities)
{
    map<string, int> cacheMap;
    int dataSize = cities.size();

    for (int i = 0; i < dataSize; i++)
    {
        string inputData = cities[i];
        cacheMap.insert(make_pair(inputData, 0));

    }
}

int main(int argc, char const *argv[])
{

    int answer = 0;
    int cacheSize = 5;
    vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};

    answer = LRU(cacheSize, cities);

    cout << "Answer : " << answer << endl;
    return 0;
}
