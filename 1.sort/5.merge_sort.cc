/*
步骤:
先递归后处理
将数组一分为二，将两个数组中小的元素存入temp，最后赋值给原数组
*/

#include <iostream>
#include <vector>
using namespace std;

static vector<int> temp;

void merge_sort(vector<int>& arr,int l,int r)
{
    if(l >= r) return ;
    int mid = (l + r) >> 1;
    merge_sort(arr,l,mid),merge_sort(arr,mid+1,r);
    int k = 0, i = l, j = mid + 1;
    while(i<= mid&& j<=r){
        if(arr[i]<=arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i<=mid) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];
    for(int m=l,n=0;m<=r;m++,n++) arr[m] = temp[n];
}

int main()
{
    vector<int> arr = {0,4,2,4,7,1,3};
    temp.assign(arr.size(),0);
    merge_sort(arr,0,arr.size()-1);
    for(auto& v: arr)
    {
        cout<< v<<" ";
    }
    return 0;
}