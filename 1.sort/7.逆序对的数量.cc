//在归并排序的基础上做
//分治,逆序对数量 = 只存在左半边的逆序对数量 + 存在两边的逆序对数量 + 只存在右边的逆序对数量
//存在两边的逆序对数量 = mid - i + 1

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
using LL = long long;

static vector<int> temp;

LL merge_sort(vector<int>& arr,int l,int r)
{
    if(l >= r) return 0;
    int mid = (l+r)>>1;
    LL res = merge_sort(arr,l,mid) + merge_sort(arr,mid+1,r);
    
    //归并
    int k = 0,i = l,j = mid+1;
    while (i <= mid && j <= r)
    {
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
            res += mid - i + 1;
        }
    }

    while(i <= mid) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for(int m = l,n=0 ; m <= r;m++,n++) arr[m] = temp[n];
    return res;
}   


int main()
{
    int n;
    vector<int> arr;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        arr.push_back(t);
    }
    temp.assign(n,0);
    cout << merge_sort(arr,0,n-1);


    return 0;
}