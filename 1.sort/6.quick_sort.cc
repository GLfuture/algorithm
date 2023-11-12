#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int>& arr,int l,int r)
{
    if (l >= r)  return;
    int i = l - 1, j = r + 1, temp = arr[(l + r + 1) >> 1];
    while(i < j)
    {
        do i++; while (arr[i] < temp);
        do j--; while(arr[j] > temp);
        if(i<j) swap(arr[i],arr[j]);
    }
    quick_sort(arr,l,i-1);
    quick_sort(arr,i,r);
}

int main()
{
    vector<int> arr = {0,4,2,4,7,1,3};
    quick_sort(arr,0,arr.size()-1);
    for(auto& v: arr)
    {
        cout<< v << " ";
    }
    return 0;
}