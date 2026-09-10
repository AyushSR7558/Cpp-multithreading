#include<iostream>
#include<thread>

using namespace std;

int main() {
    auto fun = [](int x) {
        while(x --> 0) {
            cout << x << endl;
        }
    };

    thread t(fun, 10);
    // OR
    thread t1([] (int x) {
            while(x --> 0) {
                cout << x << endl;
            }
        }, 20);
    t.join();
    t1.join();
    return 0;
}
