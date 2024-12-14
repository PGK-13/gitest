#include "Producer.cc"
#include "Consumer.cc"
#include <thread>

int main()
{
    queue<int> queue;
    Producer producer(queue);
    Consumer consumer(queue);

    thread t1(&Producer::run);
    t1.join();
    thread t2(&Consumer::run);
    thread t3(&Consumer::run);
}