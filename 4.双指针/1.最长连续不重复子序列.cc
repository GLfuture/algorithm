//第一种情况
//双指针在同一序列
/*
模板
for(i=0,j=0;i<n;i++)
{
    while(j<i&&check(i,j)) j++
    //每道题目的具体逻辑
}

*/


/*
给定一个长度为 n
 的整数序列，请找出最长的不包含重复的数的连续区间，输出它的长度。

输入格式
第一行包含整数 n
。

第二行包含 n
 个整数（均在 0∼105
 范围内），表示整数序列。

输出格式
共一行，包含一个整数，表示最长的不包含重复的数的连续区间的长度。

数据范围
1≤n≤105
输入样例：
5
1 2 2 3 5
输出样例：
3

*/


#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n,res = 0;
    cin>>n;
    vector<int> arr(n,0);
    map<int, int> m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0,j=0;i<n;i++)
    {
        m[arr[i]]++;
        while (m[arr[i]] > 1) 
        {
            m[arr[j]] --;
            j++;
        }
        res = max(res,i-j+1);

    }
    cout<<res<<endl;

    return 0;
}