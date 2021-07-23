#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void display(int A[], int len)
{
    for (int i = 0; i < len; ++i)
        cout << A[i] << " ";
    cout << endl;
}
//分成2个区: 左边为sorted区，右边为unsorted区。sorted区域内所有大于下一个待sorted值的数，都向右移一位
void insertionSort(int A[], int len)
{   
    for(int i = 1; i<= len-1; ++i) {
        int hole_pos = i;
        int curr_value = A[hole_pos];
        while(A[hole_pos-1] >= A[hole_pos] && hole_pos > 0) {
            A[hole_pos] = A[hole_pos - 1];
            hole_pos--;
            A[hole_pos] = curr_value;
        }
    }
}

int main()
{
    int A[] = {2,3,5,4,8,6,10,7,1,9};
    int len = sizeof(A) / sizeof(A[0]);
    cout << "Before Sort: " << endl;
    display(A, len);
    cout << "After Sort: " << endl;
    insertionSort(A, len);
    display(A, len);
}