#include <iostream>
#include <vector>


using namespace std;

int n;
int path[8];
int st[8];


void dfs(int u)
{
    if(u == n){
        for(int i=0;i<n;i++){
            std::cout<< path[i]<<" "; 
        }
        std::cout<<std::endl;
        return;
    }
    for(int i=1;i <= n;i++){
        if(!st[i]){
            st[i] = true;
            path[u] = i;
            dfs(u+1);
            st[i] = false;
        }
    }
}


int main()
{
    cin>>n;
    dfs(0);
    return 0;
}