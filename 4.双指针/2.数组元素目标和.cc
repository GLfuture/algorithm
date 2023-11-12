#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> arr1,arr2;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        arr1.push_back(temp);
    }
    for(int i=0;i<m;i++)
    {
        cin>>temp;
        arr2.push_back(temp);
    }
    int i=0 ,j=m-1;
    while(1)
    {
        if(arr1[i]+arr2[j] < x){
            if(i < n-1) i++;
        }
        else if(arr1[i]+arr2[j] > x){
            if(j > 0) j--;
        }
        else{
            std::cout<< i <<" "<< j <<std::endl;
            break;
        }
    }
    return 0;
}