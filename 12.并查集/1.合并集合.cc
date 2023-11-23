/*
并查集的用处：
1.快速将两个集合合并
2.询问两个元素是否在一个集合当中
*/



#include <iostream>
#include <vector>
using namespace std;

#define N   100010
int p[N];

int find(int x)
{
    if(p[x] != x){
        p[x] = find(p[x]);
    }
    return p[x];
}

int main()
{

    int m,n;
    cin >> m >>n;
    for(int i = 0;i<n;i++)
    {
        p[i] = i;
    }
    for(int i = 0 ;i < n;i++)
    {
        char op;
        int a,b;
        cin>>op >>a >>b;
        if(op == 'M'){
            p[find(a)] = find(b);
        }else{
            if(find(a) == find(b)){
                std::cout<<"Yes" <<std::endl;
            }else{ 
                std::cout<<"No"<<std::endl;
            }
        }
    }
    return 0;
}