#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int acc_balance = 0;
mutex m;

void addMoney() {
    m.lock(); 
    acc_balance++;
    cout << "Account Remaining Balance: " << acc_balance << endl;
    m.unlock();
}

int main() {
   thread t1(addMoney);
   thread t2(addMoney);
   t1.join();
   t2.join();
}
