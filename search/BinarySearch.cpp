#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::max_element;
using std::min_element;

int BinarySearch(vector<int> A, int value) {
    int start = 0;
    int end = A.size() - 1;
    while(start <= end) {
        int mid = start + (end - start)/2;  //y有时候 start+end 可能会超出int范围
        if(A[mid] == value) return mid;
        else if(A[mid] < value) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}
///////////////////递归的算法///////////////////
int BinarySearch1(vector<int> A, int start, int end, int value) {
    if(start > end) return -1;
    int mid = start + (end - start)/2;
    if(A[mid] == value) return mid;
    else if(A[mid] < value) return BinarySearch1(A, mid + 1, end, value);
    else return BinarySearch1(A, start, mid - 1, value);
}
///////////////////找到第一次出现时的位置/////////////////////////
int FindFirst(vector<int> A, int start, int end, int value) {
    int res = -1;
    while(start <= end) {
        int mid = start + (end - start)/2;
        if(A[mid] == value) {
            res = mid;
            end = mid - 1;
        }
        else if(A[mid] < value) start = mid + 1;
        else end = mid - 1;
    }
    return res;
}
///////////////////找到最后一次出现时的位置/////////////////////////
int FindLast(vector<int> A, int start, int end, int value) {
    int res = -1;
    while(start <= end) {
        int mid = start + (end - start)/2;
        if(A[mid] == value) {
            res = mid;
            start = mid + 1;
        }
        else if(A[mid] < value) start = mid + 1;
        else end = mid - 1;
    }
    return res;
}
//////////////////找到某个值出现的次数////////////////////////////
int FindCount(vector<int> A, int start, int end, int value) {
    int first = FindFirst(A, start, end, value);
    int last = FindLast(A, start, end, value);
    return (first == -1 && last == -1) ? 0 : (last - first + 1);
}
///////////////////how many times is a sorted array rotated///////////////////////
int FindRotationCount(vector<int> A, int start, int end, int N) {
    while(start <= end) {
        int mid = start + (end - start)/2;
        int next = (mid + 1) % N, prev = (mid-1+N) % N;
        if(A[start] <= A[end]) return start;
        else if(A[mid] <= A[prev] && A[mid] <= A[next]) return mid;
        else if(A[mid] <= A[end]) end = mid - 1;    //rotation的次数很少,后半段还是连续增大的
        else if(A[mid] >= A[start]) start = mid + 1;
    }
    return -1;
}
///////////////////在rotated array中寻找某个元素x//////////////////////////////
int CircularArraySearch(vector<int> A, int start, int end, int N, int value) {
    while(start <= end) {
        int mid = start + (end - start)/2;
        if(A[mid] == value) return mid;
        else if(A[mid] <= A[end]) {
            if(value >= A[mid] && value <= A[end]) start = mid + 1;
            else end = mid - 1; 
        }
        else if(A[mid] >= A[start]) {
            if(value >= A[start] && value <= A[mid]) end = mid - 1;
            else start = mid + 1; 
        }
    }
    return -1;
}
/////////////////////第k小的元素的值(有重复元素)///////////////////////////
int FindKthSmall(vector<int> A, int K) {
    int N = A.size();
    vector<int> buk(100, 0);
    vector<int> res; 
    for(int i : A) buk[i]++;
    for(int j=0; j < 100; ++j) {
        if(buk[j] == 0) continue;
        else if(buk[j] != 0) {
            res.push_back(j);
            if(res.size() == K) break;
        }
    }
    return res.back();
}
///////////////////矩阵中第k小的元素//////////////////////
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n=matrix.size();
    int l=matrix[0][0], r=matrix[n-1][n-1], mid;
    while(l<r){
        mid = l+r >> 1;     //除以2
        int cnt=0, j=n-1;
        for(int i=0;i<n;i++){
            while(j>=0 && matrix[i][j]>mid)     //每一行的元素和mid进行比较
                j--;
            cnt+=j+1;
        }
        if(cnt<k)
            l=mid+1;
        else
            r=mid;
    }
    return l;
}

int main()
{
    // vector<int> v1{1,3,3,3,7,9};
    // cout << "Enter the number you wanna search for: ";
    // int start = 0, end = v1.size()-1;
    // int value = 0;
    // cin >> value;
    // if(FindCount(v1, start, end, value) != -1)
    // cout << "The Position of the number is " << FindCount(v1, start, end, value) << endl;
    // else cout << "Not found" << endl;
    // return 0;
/////////////////******************/////////////////////
    // vector<int> v2{7,7,9,1,1,3,3,5};
    // int N = v2.size();
    // int start = 0, end = N - 1;
    // cout << "The time of the rotation is " << FindRotationCount(v2, start, end, N) << endl;
    // return 0;
/////////////////******************/////////////////////
    vector<int> v3{7,7,9,1,3,5};
    int N = v3.size();
    int start = 0, end = N - 1;
    cout << "The position is " << CircularArraySearch(v3, start, end, N, 9) << endl;
    cout << "The Kth smallest value is " << FindKthSmall(v3, 4) << endl;
    return 0;
}