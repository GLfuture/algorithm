/*
步骤：
比较相邻的元素。如果第一个比第二个大，就交换他们两个。

对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。

针对所有的元素重复以上的步骤，除了最后一个。

持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
*/
#include <iostream>
#include <vector>
using namespace std;
using ULL = long long unsigned int;
void bubble_sort(vector<int>& arr)
{
    for (ULL i = 0; i < arr.size() - 1; i++)
    {
        for (ULL j = 0; j < arr.size() - 1 -i; j++)
        {
            if(arr[j] > arr [j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main()
{
    vector<int> arr = {0, 3, 2, 7, 1, 5};
    bubble_sort(arr);
    for (auto &v : arr)
    {
        cout << v << " ";
    }
    return 0;
}