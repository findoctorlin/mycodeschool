#include <iostream>
using namespace std;

void merge(int* A, int* L, int left_length, int* R, int right_length) {
    int l = 0;
    int r = 0;
    for (int i = 0; i < left_length + right_length;) {

        if (l == left_length)A[i++] = R[r++];
        else if (r == right_length) A[i++] = L[l++];
        else A[i++] = (R[r] > L[l]) ? L[l++] : R[r++];

    }
}

void Mergesort(int* A, int length) {//using array, not vector
    if (length == 1) return;
    int mid = length / 2;   //退出条件 exit

    int* L = new int[mid];
    int* R = new int[length - mid];

    int k = 0;

    for (size_t i = 0; k < mid; i++)L[i] = A[k++];
    for (size_t i = 0; k < length; i++)R[i] = A[k++];

    Mergesort(L, mid);
    Mergesort(R, length - mid);

    merge(A, L, mid, R, length - mid);
    delete(L);
    delete(R);
}
int main() {

    int A[] = { 1,3,4,7,2,8,5,6,9 };

    int size = sizeof(A) / sizeof(A[0]);

    Mergesort(A, size);

    for (size_t i = 0; i < size; i++)cout<<A[i]<<" ";
}
