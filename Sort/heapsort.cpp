#include <iostream>
using namespace std;
//len = (2^h) - 1, 除了最后一层以外的总的个数(x的范围): 2^(h-1) - 1 = len/2 - 1
void convertHeap(int array[], int len, int x)
{
    int largest = x;
    int left = 2 * x + 1;
    int right = 2 * x + 2;

    if (left < len && array[left] > array[largest])
        largest = left;

    if (right < len && array[right] > array[largest])
        largest = right;

    if (largest != x)
    {
        swap(array[x], array[largest]);
        convertHeap(array, len, largest);
    }
}

void heapSort(int array[], int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
        convertHeap(array, len, i);     //heap建立

    for (int i = len - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);   //先把最后的元素和根元素交换
        convertHeap(array, i, 0);   //在第0层convert
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
    cout << "Before Sort: " << endl;
    display(array, len);
    cout << "After Sort: " << endl;
    heapSort(array, len);
    display(array, len);
}