#include <iostream>
#include <string.h>
using namespace std;
#define N 100010
#define M N*2

int n,m;
int res = N;
int h[N],e[M],ne[M],indx = 0;
bool pass[N];

void add(int x,int y)
{
    e[indx] = y,ne[indx] = h[x],h[x] = indx ++;
}

int dfs( int u )
{
    pass[u] = true;
    //sum存储当前数的连通块的大小，ans存的是子树的连通块的大小
    int sum = 1,ans = 0;
    for(int i = h[u];i != -1 ; i = ne[i])
    {
        int j = e[i];
        if(!pass[j]){
            int s = dfs(j);
            ans = max(ans,s);
            sum += s;
        }
    }
    ans = max(ans,n-sum);
    res = min(res,ans);
    return sum;
}


int main()
{
    memset(h,-1,sizeof(int)*N);
    cin >> n ;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y),add(y,x);
    }
    dfs(1);
    cout<<res<<endl;
    return 0;
}