#include<iostream>
#include<thread>
#include<vector>
#include<mutex>

using namespace std;

int buff = 0;
recursive_mutex m; // If we use the normal mutex it will cause the problem

void recursion(int loopFor) {
        if(loopFor == 0) return ;
       m.lock();
       cout << buff++ << endl;
       recursion(--loopFor);
       m.unlock(); 
}

int main() {
    thread t(recursion, 10);
    thread t1(recursion, 10);

    t.join();
    t1.join();
    return 0;
}
