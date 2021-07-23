#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Maxheap(int array[], int len)
{
    for(int i = len - 1; i >= 0 && (array[2*i+1] != 0 || array[2*i+2] != 0); i--) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < len && array[left] > array[largest])
            largest = left;

        if (right < len && array[right] > array[largest])
            largest = right;

        if (largest != i)
        {
            swap(array[i], array[largest]);
            Maxheap(array, len);
        }
    }
}

void display(int array[], int len)
{
    for (int i = 0; i < len; ++i)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int array[] = {2,3,5,4,8,6,10,7,1,9};
    int len = sizeof(array) / sizeof(array[0]);
    cout << "Before arrange: " << endl;
    display(array, len);
    cout << "After arrange: " << endl;
    display(array, len);
}