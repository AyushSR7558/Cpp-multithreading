#include<iostream>
#include<chrono>
#include<thread>

using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

ull EvenSum = 0;
ull OddSum = 0;

void findEven(ull start, ull end) {
    for(ull i = start; i <= end; i++) {
        if((i & 1) == 0) {
            EvenSum += i;
        } 
    }
}

void findOdd (ull start, ull end) {
    for(ull i = start; i <= end; i++) {
        if((i & 1) == 1) {
            OddSum += i;
        } 
    }
}

int main() {
    ull start = 0, end = 300000000;
    auto startTime = high_resolution_clock::now();
    thread t1(findEven, start, end);
    thread t2(findOdd, start, end);

    t1.join();
    t2.join();
    auto  stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    cout << "Duration is " << duration.count() << endl;
    return 0;
}

