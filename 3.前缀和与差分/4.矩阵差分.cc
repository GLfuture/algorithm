/*
a[i][j] = sum[i][j] - sum[i-1][j] - sum[i][j-1] + sum[i-1][j-1]

*/


#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> sum(n+2,vector<int>(m+2,0));
    vector<vector<int>> a(n+2,vector<int>(m+2,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> sum[i][j];
            a[i][j] = sum[i][j] -sum[i-1][j] -sum[i][j-1]+sum[i-1][j-1];
        }
    }

    for(int i=1;i<=q;i++)
    {
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;

        //关键
        a[x1][y1]+=c;
        a[x2+1][y1]-=c;
        a[x1][y2+1] -=c;
        a[x2+1][y2+1] +=c;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}