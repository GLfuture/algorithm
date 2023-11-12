/*
适用场景：
    找到一个数左边或者右边离他最近的数

*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        while(!s.empty() && s.top() >= temp){
            s.pop();   
        }
        if(!s.empty()) cout<<s.top()<<" ";
        else cout<<"-1 ";
        s.push(temp);
    }

    return 0;
}