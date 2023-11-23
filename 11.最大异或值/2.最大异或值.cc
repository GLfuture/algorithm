
//https://www.acwing.com/activity/content/problem/content/884/
#include <iostream>
#include <vector>
using namespace std;
#define MAX_BIT 30
const int M = 100010,N = 3000000;
int tire[N][2];
int arr[M];
static int idx=0;

void Insert(int num)
{
    int p = 0;
    //~i 相当于i>=0
    for(int i=MAX_BIT ; ~i ; i--)
    {
        int &s = tire[p][num>>i&1];
        if(!s) s=++idx;
        p = s;
    }

}

int Query(int num)
{
    int p = 0,res = 0;
    for(int i =MAX_BIT;i>=0;i--){
        int s = num>>i & 1;
        if(tire[p][!s])
        {
            res += 1 <<i;
            p = tire[p][!s];
        }else p = tire[p][s];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        Insert(arr[i]);
    }
    
    int m = 0;
    for(int i=0;i<n;i++){
        m = std::max(m,Query(arr[i]));
    }
    std::cout<<m<<std::endl;
    return 0;
}


