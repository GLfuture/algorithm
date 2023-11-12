/*
步骤:
将第一待排序序列第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列。

从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。（如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。）
*/


#include <iostream>
#include <vector>
using namespace std;
using ULL = long long unsigned int;

void insertion_sort(vector<int>& arr)
{
    int temp = 0;
    for (ULL i = 1; i < arr.size(); i++)
    {
        temp = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 7, 5, 7, 4, 1};
    insertion_sort(arr);
    for (auto &v : arr)
    {
        cout << v << " ";
    }
    return 0;
}