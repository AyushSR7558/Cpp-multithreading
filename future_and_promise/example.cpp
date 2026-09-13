#include<iostream>
#include<thread>
#include<future>

using namespace std;

void findOddSum(promise<int> p, int st, int ed) {
    int sum = 0;
    for(int i = st; i <= ed; i++) {
        if(i & 1)
            sum += i;
    }
    
    p.set_value(sum);
}

void findEvenSum(promise<int> p, int st, int ed) {
    int sum = 0;
    for(int i = st; i <= ed; i++) {
        if((i & 1) == 0)
            sum += i;
    }

    p.set_value(sum);
}

int main() {
    promise<int> even, odd;
    future<int> evenSumresult = even.get_future(),oddSumresult = odd.get_future();
    thread t1(findOddSum, move(odd), 0, 100);
    thread t2(findEvenSum, move(even), 0, 100);
    int result = evenSumresult.get() + oddSumresult.get();
    cout << result << endl;
    t1.join();
    t2.join();
}
