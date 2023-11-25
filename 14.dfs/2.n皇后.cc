#include <iostream>
#include <stdio.h>
using namespace std;

int n;

int col[10],dg[20],rdg[20];
char graph[10][10];

void dfs(int row)
{
    if(row == n){
        for(int i = 0;i < n; i++) puts(graph[i]);
        cout <<endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!col[i] && !dg[row+i] && !rdg[ n - row + i]){
            graph[row][i] = 'Q';
            col[i] = dg[row+i] = rdg[ n - row + i] = 1;
            dfs(row + 1);
            col[i] = dg[row+i] = rdg[ n - row + i] = 0;
            graph[row][i] = '.';
        }
    }
}

int main()
{

    cin>>n;
    for(int i = 0;i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j ++)
        {
            graph[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}