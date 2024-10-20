#include <iostream>
#include <thread>

using namespace std;

void output(int i)
{
    cout << i << endl;
}

int main()
{
    auto fn = [](const int *a)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << *a << endl;
        }
    };

    [fn]
    {
        int a = 1010;
        thread t(fn, &a);
        t.detach();
    }();
    
}