#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

int divi(int a, int b) {
    return a / b;
}

void print(int a) {
    cout << "The value is: " << a << endl;
}

void foreach(vector<int>& p, void (*ptr) (int)) {
    for(int i = 0; i < p.size(); i++) 
        ptr(p[i]);
}

int main() {
    typedef int (*Operation) (int, int);
    int (*ptr) (int, int) = add;
    cout << add(2,3) << endl;
    Operation op = add;
    cout << op(2, 3) << endl;
    vector<int> p = {1, 2, 3, 4, 5, 6};
    foreach(p, print);
}
