#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int situ[4][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0},
};


int bfs(string start)
{
    queue<string> q;
    q.push(start);
    unordered_map<string,int> res;
    res[start] = 0;
    string end = "12345678x";
    while (!q.empty())
    {
        string t = q.front();
        q.pop();
        int dis = res[t];
        if(t == end) return dis;
        int pos = t.find('x');
        int x = pos / 3 , y = pos % 3;
        for(int i=0;i<4;i++)
        {
            int nx = x + situ[i][0],ny = y + situ[i][1];
            if(nx >=0 && nx < 3 && ny >= 0 && ny < 3){
                swap(t[pos],t[3*nx+ ny]);
                //需要判断当前图的状态是否存在过
                if(!res.count(t)){
                    res[t] = dis + 1;
                    q.push(t);
                }
                //因为改变了迷宫，所以需要恢复现场
                swap(t[pos],t[3*nx+ ny]);
            }
        }
    }
    return -1;
}

int main()
{
    string start;
    for(int i=0;i<9;i++)
    {
        char t;
        cin>>t;
        start += t;
    }
    cout<< bfs(start);
    return 0;
}