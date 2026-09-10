#include<iostream>
#include<thread>

using namespace std;

void run(int x) {
    while(x --> 0)
        cout << x << endl;
    cout << "Join ends here" << endl;
    this_thread::sleep_for(chrono::seconds(3));
}

int main() {
    thread t(run, 10);
    cout << "Waiting for join to complete" << endl;
    t.join(); 
    cout << "After the join" << endl;
}
