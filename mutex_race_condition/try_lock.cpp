#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

int counter = 0;
mutex m;

void increaseTheCounter() {
    for(int i = 0; i < 100000; i++) {
        if(m.try_lock()) {
            counter++;
            m.unlock();
        }
    }
}

int main() {
    thread t1(increaseTheCounter);
    thread t2(increaseTheCounter);

    t1.join();
    t2.join();

    cout << counter << endl;
    return 0;
}
