#include<iostream>
#include<thread>

using namespace std;

void run(int x) {
    while(x --> 0) {
        cout << x << endl;
    }
    this_thread::sleep_for(chrono::seconds(5));
}

int main() {
    std:: thread t1(run, 10);
    cout << "main()" << endl;
    t1.detach();
    cout << "main() after" << endl;
}
