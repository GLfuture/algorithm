/*
待搜索字符串越长，性能越好

适用：
字符串匹配

https://www.acwing.com/activity/content/problem/content/869/
next数组表示j从哪个地方开始
*/



#include <iostream>

using namespace std;
const int N = 100010,M = 1000010;

int n,m;
char p[N],s[M];
int ne[N];


int main()
{

    scanf_s("%d %s %d %s",n,p+1,m,s+1);
    for(int i=2,j = 0;i<=n;i++)
    {
        while (j &&p[i]!=p[j+1])  j=ne[j];
        if(p[i] == p[j+1]) j++;
        ne[i] =j;
    }
    for(int i=1,j=0;i<=m;i++)
    {
        while (j && s[i]!=p[j+1]) j = ne[j];
        if(s[i]==p[j+1]) j++;
        if(j == n)
        {
            cout<< i-n <<" ";
            j = ne[j];
        }
        
    }

    return 0;
}