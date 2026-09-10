#include<iostream>
#include<thread>

using namespace std;

void fun(int x) {
    while(x --> 0) {
        cout << x << endl;
    }
}

int main() {
    void (*ptr) (int) = fun;
    thread t1(ptr, 20);
    thread t2(fun, 50);
       
    t1.join();
    t2.join(); 
}
