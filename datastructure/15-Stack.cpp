#include <iostream>
using std::cout;
using std::endl;

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;           //empty stack

bool Isempty()
{
    if(top == -1) return true;
    else return false;
}
void Push(int x)
{
    if(top == MAX_SIZE - 1)
    {
        cout << "ERROR: Stackoverflow" << endl;
        return;
    }
    A[++top] = x;
}

void Pop()
{
    if(top == -1)
    {
        cout << "ERROR: Empty stack!" << endl;
        return;
    }
    top--;
}
void Print() {
    cout << "stack is: " << endl;
    for (int i = 0; i <= top; ++i){
        cout << A[i] << "  ";
    }
    cout << endl;
}

int main() {
    Push(2);
    Push(0);
    Push(2);
    Push(1);
    Pop();
    Push(2);
    Print();
    return 0;
}