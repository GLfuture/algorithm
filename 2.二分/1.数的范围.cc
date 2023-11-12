/*
给定一个按照升序排列的长度为 n
 的整数数组，以及 q
 个查询。

对于每个查询，返回一个元素 k
 的起始位置和终止位置（位置从 0
 开始计数）。

如果数组中不存在该元素，则返回 -1 -1。

输入格式
第一行包含整数 n
 和 q
，表示数组长度和询问个数。

第二行包含 n
 个整数（均在 1∼10000
 范围内），表示完整数组。

接下来 q
 行，每行包含一个整数 k
，表示一个询问元素。

输出格式
共 q
 行，每行包含两个整数，表示所求元素的起始位置和终止位置。

如果数组中不存在该元素，则返回 -1 -1。

数据范围
1≤n≤100000

1≤q≤10000

1≤k≤10000

*/


#include <iostream>
#include <vector>
using namespace std;

bool check1(int n,int x)
{
    if( x <= n ) return true;
    return false;
}


bool check2(int n,int x)
{
    if(x >= n) return true;
    return false;
}

int main()
{
    vector<int> arr;
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        arr.push_back(t);
    }
    for(int i=0;i < q;i++)
    {
        int t;
        cin>>t;
        int l = 0,r = n-1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            //中间数满足大于等于输入数可得出，小于等于输入数的最大数在左半边
            if(check1(arr[mid],t))   r = mid;
            else l = mid+1;
        }

        if(arr[l] != t) cout<<"-1 -1"<<endl;
        else{
            cout<< r <<" ";
            l = 0,r = n-1;
            while(l<r)
            {
                int mid = (l+r+1)>>1;
                //中间数满足小于等于输入数可得出，大于等于输入数的最小数在右半边
                if (check2(arr[mid], t))
                    l = mid;
                else
                    r = mid-1;
            }
            cout<<l<<endl;
        }

    }


    return 0;
}