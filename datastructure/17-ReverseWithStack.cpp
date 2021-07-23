#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<stack>
#include<string>
#include<iterator>
using std::cout;
using std::endl;
using std::stack;
using std::cin;
void Reverse(char* C, int n)   //char* C也是数组形参的一种
{
    stack<char> S;
    for(int i = 0; i < n; ++i) {
        S.push(C[i]);
    }
    for(int i = 0; i < n; ++i) {
        C[i] = S.top();
        S.pop();
    }
}

int main() {
    char C[50];
    cout << "Enter a string" <<endl;
    cin >> C;
    // Reverse(C, sizeof(C)/sizeof(C[0]));
    Reverse(C, std::end(C) - std::begin(C));
    // printf("Output is = %s", C);
    cout << C << endl;
}