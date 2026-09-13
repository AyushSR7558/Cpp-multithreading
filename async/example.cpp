#include<iostream>
#include<thread>
#include<future>

using namespace std;
typedef unsigned long long ull;


ull findOdd(ull start, ull end) {
    ull OddSum = 0;
    for(ull i = start; i <= end; i++) {
        if(i & 1) {
            OddSum += i;
        }
    }

    return OddSum;
}

int main() {
    ull start = 0, end = 190000000;

    cout << "Thread created if policy is std::launch::async!!" << endl;
    future<ull> OddSum = async(launch::deferred, findOdd, start, end);

    cout << "Waiting for result" << endl;
    cout << "OddSum : " << OddSum.get() << endl;


    cout << "Completed!" << endl;
    return 0;
}
