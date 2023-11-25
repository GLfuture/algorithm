/*
边权为1的最短路问题才可以用bfs
dp是特殊的最短路问题
dp问题一般不拿最短路算法使用，因为最短路算法时间复杂度比较高，dp问题可以巧解
*/

#include <iostream>
#include <queue>
using namespace std;
int n,m;
int p[101][101],d[101][101];
//d数组的作用是存当前点距离原点的最短路径长度(即第一次到达该点经过的步数，后续不再进行修改)
int dir[4][2] = {
    {0,1},
    {1,0},
    {-1,0},
    {0,-1}
};

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            cin>>p[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for(int i=0;i < 4;i++)
        {
            int x = t.first + dir[i][0] , y = t.second + dir[i][1];
            if(x >= 0 && x < n && y >= 0 && y < m && !p[x][y] && !d[x][y]){
                d[x][y] = d[t.first][t.second] +1;
                q.push(make_pair(x,y));
            }
        }
    }
    cout<< d[n-1][m-1];
    return 0;
}