/*
步骤：
1.按区间左端点排序
2.  （1）当区间有交集时，更新end
    （2）当区间包含时，end不变
    （3）当区间不相交时,合并完毕前一个区间,更新beg和end
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,num = 0,st,ed,x,y;
    vector<pair<int,int>> arr;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        arr.push_back({x,y});
    }
    sort(arr.begin(),arr.end(),[](pair<int,int> a,pair<int,int> b){
        return a.first < b.first;
    });

    st = arr[0].first;
    ed = arr[0].second;
    for(int i=1;i<n;i++)
    {
        if(arr[i].first > ed)
        {
            st = arr[i].first;
            ed = arr[i].second;
            num++;
        }else 
        {
            ed = max(ed,arr[i].second);
        }
    }
    cout<< num+1 <<endl;
    return 0;
}