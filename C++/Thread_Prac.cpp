#include <pthread.h>
#include <thread>
#include <iostream>

using namespace std;

pthread_t p[3];

void *show(void *arg)
{
    std::cout<<"show!"<<std::endl;
}

int main()
{

    pthread_create(&p[0], NULL, show, NULL );



    return 0;
}