#include<iostream>
#include<mutex>
#include<thread>

using namespace std;
int X, Y;
mutex m1, m2;

void incrementXorY(int& var, mutex& m,  const string s) {
    for(int i = 0; i < 5; i++) {
        m.lock();
        var++;
        cout << s << " " << var << endl;
        m.unlock();
        this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void consumeXY() {
    int useCount = 0; 
    int XplusY = 0;
    while(1) {
        int lockResult = try_lock(m1, m2);
        if(lockResult == -1) {
            if(X != 0 && Y != 0) {
                --useCount;
                XplusY += X + Y;
                X = 0;
                Y = 0;
                cout << "XplusY" << XplusY << endl;
            }
            m1.unlock();
            m2.unlock();
            if(useCount == 0) break;
        }
    }
}

int main() {
    thread t1(incrementXorY, ref(X), ref(m1), "X"); 
    thread t2(incrementXorY, ref(Y), ref(m2), "Y");
    thread t3(consumeXY); 

    t1.join();
    t2.join();
    return 0;
}
