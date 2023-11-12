/*
用于将某一区间加上或减去同一个数

a[i] = sum[i] - sum[i-1]
*/
/*
输入一个长度为 n
 的整数序列。

接下来输入 m
 个操作，每个操作包含三个整数 l,r,c
，表示将序列中 [l,r]
 之间的每个数加上 c
。

请你输出进行完所有操作后的序列。

输入格式
第一行包含两个整数 n
 和 m
。

第二行包含 n
 个整数，表示整数序列。

接下来 m
 行，每行包含三个整数 l，r，c
，表示一个操作。

输出格式
共一行，包含 n
 个整数，表示最终序列。

数据范围
1≤n,m≤100000
,
1≤l≤r≤n
,
−1000≤c≤1000
,
−1000≤整数序列中元素的值≤1000

输入
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1

输出
3 4 5 3 4 2
*/


#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> sum(n+1,0), a(n+2,n);
    for(int i=1;i <= n;i++)
    {
        cin >> sum[i];
        a[i] = sum[i]-sum[i-1];
    }

    for(int i = 1;i<= m;i++)
    {
        int l,r,c;
        cin >> l >> r >>c;
        a[l]+= c;
        a[r+1] -= c;
    }
    
    for(int i=1;i<=n;i++)
    {
        sum[i] = sum[i-1] + a[i];
        cout<<sum[i]<<" ";
    }
    return 0;
}