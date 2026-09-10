#include<iostream>
#include<thread>

using namespace std;

void run() {
    cout << "Thread ends";
    this_thread::sleep_for(chrono::seconds(3));
}

int main() {
    thread t(run);
    t.detach();  
    return 0;
}
