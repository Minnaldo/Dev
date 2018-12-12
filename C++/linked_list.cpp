#include <iostream>

using namespace std;

template <typename ll>
class linkedList
{
  public:
    addLink(ll data, linkedList *left, linkedList *right)
    {
        this->data = data;
        this->front = left;
        this->rear = right;
    }


  private:
    ll data;
    linkedList *front;
    linkedList *rear;
};

int main(int argc, char const *argv[])
{

    return 0;
}