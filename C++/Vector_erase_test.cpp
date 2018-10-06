#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    // vector<int>::iterator itr = vec.begin(); --> 에러
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);

    vector<int>::iterator itr = vec.begin();
    cout << *itr << endl; //예상 : 0
    // itr = vec.erase(itr);

    vec.erase(vec.begin());
    vec.erase(vec.begin());
    vec.erase(vec.begin());

    if(vec.begin() == vec.end()){
        cout<<"adlkjf"<<vec.size()<<endl;
    }

    cout << *itr << endl; //예상 : 1


    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(4);

    return 0;
}