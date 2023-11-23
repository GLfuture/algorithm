/*
https://www.acwing.com/problem/content/839/

*/


#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int p[100010];
int blk_size[100010];

int find(int x)
{
    if(p[x] != x){
        p[x] = find(p[x]);
    }
    return p[x];
}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        blk_size[i] = 1;
    }
    for(int i=0;i<m;i++)
    {
        char op[5];
        cin >> op;
        if(op[0] == 'C'){
            int q1,q2;
            cin>>q1>>q2;
            if(find(q1) == find(q2)) continue;
            blk_size[find(q2)] += blk_size[find(q1)];
            p[find(q1)] = find(q2);
        }else{
            if(op[1] == '1')
            {
                int q1,q2;
                cin>>q1>>q2;
                if(find(q1)==find(q2)){
                    std::cout<<"Yes"<<std::endl;
                }else{
                    std::cout<<"No"<<std::endl;
                }
            }
            else if(op[1]=='2')
            {
                int p;
                cin>>p;
                std::cout<<blk_size[find(p)]<<std::endl;
            }
        }

    }
    return 0;
}