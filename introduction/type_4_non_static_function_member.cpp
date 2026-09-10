#include<iostream>
#include<thread>

using namespace std;

class Base {
    public:
        void run(int x) {
            cout << x << endl;
        }
};

int main() {
    void (Base::*ptr) (int) = &Base::run;
    Base b;

    thread t(ptr, b, 10);
    t.join(); 
}
