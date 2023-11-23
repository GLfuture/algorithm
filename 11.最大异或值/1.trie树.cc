//https://www.acwing.com/problem/content/description/837/
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int>> arr;
vector<int> cnt;
static int indx = 0;
enum OP_TYPE{
    OP_INSERT,
    OP_QUERY,
};

void Insert(const string& str)
{
    int p = 0;
    for(int i = 0 ;i < str.length() ; i++)
    {
        int pos = str[i] - 'a';
        if(!arr[p][pos]) arr[p][pos] = ++indx;
        p = arr[p][pos];
    }
    cnt[p]++;
}

int Query(const string& str)
{
    int p=0;
    for(int i=0;i<str.length();i++)
    {
        int pos = str[i]-'a';
        if(!arr[p][pos]) return 0;
        p = arr[p][pos];
    }

    return cnt[p];
} 



int main()
{
    int n;
    cin>>n;
    char op[2] = {'I','Q'};
    char x;
    string str;
    arr.assign(100010,vector<int>(26,0));
    cnt.assign(100010,0);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        getchar();
        cin>>str;
        if(x == op[OP_INSERT]) Insert(str);
        else if(x == op[OP_QUERY]) cout<<Query(str)<<endl;
    }
    return 0;
}