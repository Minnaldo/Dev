#include <iostream>
#include <mutex>
#include <thread>

/**
 *  * std::mutex, std::recursive_mutex 두 종류
 */

using namespace std;

mutex mtx;

void ThreadFunc(int nID, int &val)
{
    for (int i = 0; i < 5; ++i)
    {
        mtx.lock(); // mutex객체 Lock, Critical Section 진입

        cout << "Value of " << nID << " -> " << val << endl;
        ++val;

        mtx.unlock(); // mutex객체 unlock, Critical Section 탈출
    }
}

int main(int argc, char const *argv[])
{
    int val = 0;

    thread th1(ThreadFunc, 0, ref(val));
    thread th2(ThreadFunc, 1, ref(val));

    th1.join();
    th2.join();

    return 0;
}