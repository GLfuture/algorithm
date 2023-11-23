/*
只需要使用堆的down或up操作

时间复杂度：
up/down:O(logn)
插入/删除:O(logn)
求最小值：O(1)


down操作的思路:
    大的元素往下沉,然后比较左右节点大小,保证左边节点小于右边节点
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define ARR_SIZE 100010 

int n,m,sz;
int h[ARR_SIZE];

void down(int c)
{
    int t = c;
    if( 2 * c <= sz && h[ 2 * c] < h[ t ]) t = 2 * c;
    if( 2 * c + 1 <= sz && h[c * 2 + 1] < h[t]) t = 2 * c + 1;
    if( t != c){
        swap( h[t] , h[c]);
        down(t);
    }
}



int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>h[i];
    sz = n;
    for(int i= n/2;i;i--) down(i);
    while(m--){
        cout<<h[1]<<" ";
        //删除堆顶元素，详见8.堆
        h[1] = h[sz];
        sz--;
        down(1);
    }
    return 0;
}