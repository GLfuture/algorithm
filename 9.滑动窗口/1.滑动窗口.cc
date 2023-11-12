/*
应用：找多区间的最大值或者最小值

思路:
（拿双端队列存储单调队列的下标）
当队列不为空且队头的下标在当前下标-窗口长度之外（即在窗口之外）把队头元素弹出
该队列就维护了窗口的最值下标的单调性
队头元素即为窗口内的最值下标
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
    int n,len;
    cin>>n>>len;
    deque<int> q;
    vector<int> arr;
    arr.assign(n,0);
    for(int i = 0 ;i <n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i <n ;i++)
    {
        if(!q.empty() && q.front() < i-len+1) q.pop_front();
        while(!q.empty()&& arr[q.back()]>=arr[i]){
            q.pop_back();
        }
        q.push_back(i);
        if(i >= len - 1) cout<<arr[q.front()]<<" ";
    }
    cout<<endl;
    q.clear();
    for(int i=0; i <n ;i++)
    {
        if(!q.empty() && q.front() < i-len+1) q.pop_front();
        while(!q.empty()&&arr[q.back()] <= arr[i]){
            q.pop_back();
        }
        q.push_back(i);
        if(i >= len - 1) cout<<arr[q.front()]<<" ";
    }
    return 0;
}