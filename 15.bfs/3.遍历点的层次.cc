#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
int n,m;
//用三个数组存储比用邻接矩阵存省空间
//int graph[10010][10010];
int g[100010],ne[100010],e[100010],indx = 0;

//映射数组，模板记住就可以
//indx为唯一值，用于将所用边映射到ne数组和e数组
void add(int x,int y)
{
    e[indx] = y, ne[indx] = g[x] , g[x] = indx++; 
}


int bfs(int p)
{
    queue<int> q;
    q.push(p);
    int d[100010];
    memset(d,-1,100010*sizeof(int));
    d[p] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for(int i = g[t];i != -1; i = ne[i])
        {
            int j = e[i];
            if(d[j] == -1){
                d[j] = d[t] + 1;
                q.push(j);
            }
        }  
    }
    return d[n];
}



int main()
{
    cin>>n>>m;
    memset(g,-1,sizeof(int)*100010);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
    }
    cout<<bfs(1);
    return 0;
}