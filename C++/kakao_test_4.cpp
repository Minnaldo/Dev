#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int answer = 0;
    vector<int> food_times = {3, 1, 2};
    vector<int>::iterator itr;
    long k = 5;
    int food_size = food_times.size();
    int tmp = 0;
    int time = 0;

    while (true)
    {
        if (time != k)
        {

            time++;
            tmp = time % food_size;
            if (food_times.at(tmp - 1) == 0)
            {
                // food_times.erase(find(food_times.begin(), food_times.end(), 0));
            }
            food_times.at(tmp - 1) -= 1;
        }
        else
        {
            time += food_size;
            answer = (time % food_size) -1 ;
        }

        if (food_times.empty())
        {
            answer = -1;
        }
    }

    cout << "Answer : " << answer << endl;
    return 0;
}
