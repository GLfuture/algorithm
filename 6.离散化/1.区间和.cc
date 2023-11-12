/*
假定有一个无限长的数轴，数轴上每个坐标上的数都是 0
。

现在，我们首先进行 n
 次操作，每次操作将某一位置 x
 上的数加 c
。

接下来，进行 m
 次询问，每个询问包含两个整数 l
 和 r
，你需要求出在区间 [l,r]
 之间的所有数的和。

输入格式
第一行包含两个整数 n
 和 m
。

接下来 n
 行，每行包含两个整数 x
 和 c
。

再接下来 m
 行，每行包含两个整数 l
 和 r
。

输出格式
共 m
 行，每行输出一个询问中所求的区间内数字和。

数据范围
−109≤x≤109
,
1≤n,m≤105
,
−109≤l≤r≤109
,
−10000≤c≤10000
输入样例：
3 3
1 2
3 6
7 5
1 3
4 6
7 8
输出样例：
8
0
5

*/
//核心：离散化 + 差分

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int find(const vector<int>& arr,int indx)
{
    int i = 0,j = arr.size() -1 ;
    while( i < j)
    {
        int mid = (i+j)>>1;
        if(arr[mid] >= indx) j = mid;
        else i = mid + 1;
    }
    return i + 1;
}
static const int N = 300010;

static int a[N],s[N];

int main()
{
    vector<int> all_index;
    vector<pair<int,int>> own,query;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        own.push_back({x,y});
        all_index.push_back(x);
    }


    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        query.push_back({x,y});
        all_index.push_back(x);
        all_index.push_back(y);
    }

    //index去重加排序
    sort(all_index.begin(),all_index.end());
    all_index.erase(unique(all_index.begin(),all_index.end()),all_index.end());

    //把含有值的下标的值映射进a数组
    for(int i = 0;i<own.size();i++)
    {
        int x = find(all_index,own[i].first);
        a[x] += own[i].second;
    }

    //求前缀和
    //需要多一个元素
    for(int i = 1; i <= all_index.size();i++) s[i] = a[i]+s[i-1];

    for(int i=0;i<query.size();i++)
    {
        int l = find(all_index,query[i].first);
        int r = find(all_index,query[i].second);
        cout<< s[r] - s[l-1]<<endl;
    }

    return 0;
}