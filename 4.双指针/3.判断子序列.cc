#include <iostream>
#include <vector>


using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> arr1,arr2;
    arr1.assign(n,0);
    arr2.assign(m,0);
    for(int i = 0;i < n;i++)
    {
        cin>> arr1[i];
    }
    for(int j=0;j<m;j++)
    {
        cin>>arr2[j];
    }
    int i=0,j=0;
    while(1)
    {
        if(arr1[i]!=arr2[j]) j++;
        else{
            i++;
            j++;
        }
        if(i == n){
            cout<<"Yes"<<endl;
            break;
        }
        if( j == m){
            cout<<"No"<<endl;
            break;
        }
    }

    return 0;
}