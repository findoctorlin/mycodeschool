#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i <= n-1; ++i)
        std::cout << A[i] << "  ";
}
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
//设置pIndex观察点（初始为0）用i遍历：所有小于pivot的A[i]都会和A[pIndex]交换
int Partition(int *A, int start, int end) {
    int pivot = A[end];
    int swap_pos = start;
    for(int i = start; i <= end - 1; ++i) {
        if(A[i] <= pivot) {
            swap (A[i], A[swap_pos]);
            swap_pos++;
        } 
    }
    swap(A[swap_pos], A[end]);
    return swap_pos;
}

void Quicksort(int *A, int start, int end)
{
    if(start < end) {
        int partitionIndex = Partition(A, start, end);
        Quicksort(A, start, partitionIndex - 1);
        Quicksort(A, partitionIndex + 1, end);
    }
}
//首尾两指针 i++ j--
void Quicksort1(int *A, int start, int end)
{
    if(start < end) {
        int pivot = A[end];
        int i = start;
        int j = end - 1;
        while(true) {
            while(i < end && A[i] <= pivot) i++;
            while(j > start && A[j] >= pivot) j--;
            if(i >= j) break;
            swap(A[i], A[j]);
        }
        swap(A[end], A[i]);
        Quicksort1(A, start, i-1);
        Quicksort1(A, i+1, end);
    }
}

int main()
{
    int A[] = {7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(A) / sizeof(A[0]);
    std::cout << "Before Quick Sort :" << std::endl;
    printArray(A, n);
    std::cout << std::endl;

    // Quicksort1(A, 0, n-1);
    sort(A, A + 7, 0);

    std::cout << "After Quick Sort :" << std::endl;
    printArray(A, n);
    return 0;
}