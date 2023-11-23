/*
如何实现一个堆:
1.插入一个数                heap[ ++size ] = x; up(size);
2.求集合中的最小值          heap[1];    
3.删除最小值                heap[1] = heap[size];size--;down(1);
4.删除任意一个元素          heap[k] = heap[size];size--;down(k);up(k);
5.修改任意一个元素          heap[k] = x;down(k);up(k);

堆排序实现见sort 8.heap_sort.cc
*/

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

#define ARR_SIZE 100010 

int n,m,sz;
//ph[k]表示第k个插入的元素指向h的哪个下标,hp[k]表示h的下标k的数是在ph中的下标(即hp[k]存放的是h中下标为k的数是第几个插入进来的)
int h[ARR_SIZE],ph[ARR_SIZE],hp[ARR_SIZE];

//通过下标交换元素
void heap_swap(int a,int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
    
}

void down(int c)
{
    int t = c;
    if( 2 * c <= sz && h[ 2 * c] < h[ t ]) t = 2 * c;
    if( 2 * c + 1 <= sz && h[c * 2 + 1] < h[t]) t = 2 * c + 1;
    if( t != c){
        heap_swap( t , c);
        down(t);
    }
}

void up(int c)
{
    while (c/2 && h[c/2] >h[c])
    {
        heap_swap(c/2,c);
        c /=2;
    }
    
}

int main()
{
    cin>>n;
    while(n--)
    {
        char op[2];
        cin>>op;
        int k,x;
        if(!strcmp(op,"I"))
        {
            cin>>x;
            m++;
            sz++;
            ph[m] = sz,hp[sz] = m;
            h[sz] = x;
            up(sz);
        }
        else if(!strcmp(op,"PM")) cout<<h[1]<<std::endl;
        else if(!strcmp(op,"DM"))
        {
            heap_swap(1,sz);
            sz--;
            down(1);
        }
        else if(!strcmp(op,"D")){
            cin>>k;
            k= ph[k];
            heap_swap(k,sz);
            sz--;
            down(k),up(k);
        }
        else{
            cin>>k>>x;
            k = ph[k];
            h[k] = x;
            down(k),up(k);
        }
    }
    return 0;
}