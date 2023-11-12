/*
步骤:
1.把第k位移到最后一位 n>>k
2.看个位是几 x&1

lowbit(x)：返回n的最后一个1，剩余位数用0补齐
        x&-x
*/

#include <iostream>
#include <vector>
using namespace std;

int lowbit(int x)
{
    return x&(-x);
}



int main()
{
    int n,temp,num;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        num = 0;
        cin>>temp;
        while(temp){
            int x = lowbit(temp);
            num ++;
            temp -= x;
        }
        cout<<num<<" ";
    }
    return 0;
}