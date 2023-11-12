/*
步骤：
首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
重复第二步，直到所有元素均排序完毕。
*/

#include <iostream>
#include <vector>
using namespace std;
using ULL = long long unsigned int;
void selection_sort(vector<int> &arr)
{
    int indx = 0;
    for (ULL i = 0; i < arr.size() - 1; i++)
    {
        indx = i;
        for (ULL j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[indx])
            {
                indx = j;
            }
        }
        swap(arr[i], arr[indx]);
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 7, 5, 7, 4};
    selection_sort(arr);
    for (auto &v : arr)
    {
        cout << v << " ";
    }
    return 0;
}