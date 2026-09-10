#include<iostream>
#include<thread>

using namespace std;

class Base {
    public:
        void operator () (int x) {
            while(x --> 0) {
                cout << x << endl;
            }
        }
};

int main() {
    Base b;
    thread t(Base(), 10);
    t.join();
}
