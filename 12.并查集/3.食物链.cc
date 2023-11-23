/*
https://www.acwing.com/problem/content/description/242/
*/

#include <iostream>
using namespace std;

int p[50010],d[50010];

int find(int x)
{
    if(p[x] != x){
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;  
    }
    return p[x];
}



int main()
{

    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        p[i]=i;
    }
    int sum = 0;
    for(int i=0;i<k;i++)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if (x > n || y > n){
            sum++;
            continue;
        }
        int px= find(x),py= find(y);
        if(op == 1){
            if(px == py && (d[x] - d[y] ) % 3) sum++;
            else if(px!=py)
            {
                p[px] = py;
                d[px] = d[y] - d[x];
            }
        }else{
            if(px == py && (d[x]-d[y]-1)%3) sum++;
            else if(px!=py){
                p[px] = py;
                d[px] = d[y]+1-d[x]; 
            }
        }
    }
    std::cout<<sum<<std::endl;
    return 0;
}