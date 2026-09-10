#include<iostream>
#include<thread>

using namespace std;

class Base {
    public:
        static void run(int x) {
            cout << x << endl;
        }
};

int main() {
    void (*ptr) (int) = &Base::run;
    Base b;

    thread t(&Base::run, 10);
    t.join(); 
}
