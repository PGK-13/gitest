#pragma once
#include <iostream>
#include <queue>
#include <cmath>
#include <mutex>
using namespace std;

class Consumer{
public:
    Consumer(queue<int> q) {
        queue = q;
    }

    void run(){
        // 很大概率出错，若两个线程一起执行的话
        while (true){
            queue_mutex.lock();
            if(!queue.empty()){
                int num = queue.front();
                queue.pop();
                if(is_Primer(num)) {
                    cout << num << " is a primer num." << endl;
                }else {
                    cout << num << " is not a primer num." << endl;
                }
            }else{
                break;
            }
            queue_mutex.unlock();
        }
    }
private:
    queue<int> queue;
    mutex queue_mutex;
    bool is_Primer(int num){
        if (num <= 1)
            return false;
        for(int i = 2; i < sqrt(num); i++)
            if(num % i == 0)
                return false;
        return true;
    }
};