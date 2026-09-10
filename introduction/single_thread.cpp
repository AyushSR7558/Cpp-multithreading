#include<bits/stdc++.h>
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

    findOdd(start, end);
    findEven(start, end);

    auto startTime = high_resolution_clock::now();
    findEven(start, end);
    findOdd(start,end);
    auto  stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    cout << "Duration is " << duration.count() << endl;
    return 0;
}
