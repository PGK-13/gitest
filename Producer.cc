#pragma once
#include <iostream>
#include <queue>
#include <random>
using namespace std;

class Producer{
public:
    Producer(queue<int> q) {
        queue = q;
    }

    void run() {
        random_device rd;  // 真实随机数生成器，用于种子
        mt19937 gen(rd()); // 使用梅森旋转算法生成随机数
        uniform_int_distribution<> distrib(1, 100000000); // 定义随机数范围 [1, 100]
        for (int i = 0; i < 100; i++) {
            int random_number = distrib(gen);
            queue.push(random_number);
            cout << random_number << " insert success!" << endl;
        }
    }

private:
    queue<int> queue;
};