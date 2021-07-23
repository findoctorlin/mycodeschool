#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
//适用于有重复元素的
void display(int array[], int len)
{
    for (int i = 0; i < len; ++i)
        cout << array[i] << " ";
    cout << endl;
}

void selectionSort(int array[], int len)
{   
    for(int i = 0; i <= len-2; ++i) {
        int index = i;
        for(int j = i+1; j <= len-1; ++j) {
            if(array[j] <= array[index])
                index = j;  //不停更新index，找到每一段里面最小值的index
        }
        swap(array[i], array[index]);
    }
}

int main()
{
    int array[] = {2,3,5,4,8,6,10,7,1,1,9};
    int len = sizeof(array) / sizeof(array[0]);
    cout << "Before Sort: " << endl;
    display(array, len);
    cout << "After Sort: " << endl;
    selectionSort(array, len);
    display(array, len);
}