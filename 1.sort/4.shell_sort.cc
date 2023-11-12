/*
步骤:
选择一个增量序列 t1，t2，……，tk，其中 ti > tj, tk = 1；

按增量序列个数 k，对序列进行 k 趟排序；

每趟排序，根据对应的增量 ti，将待排序列分割成若干长度为 m 的子序列，分别对各子表进行直接插入排序。仅增量因子为 1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。
*/


#include <iostream>
#include <vector>
using namespace std;

void shell_sort(vector<int>& arr)
{
    int h = 1;
    int len = arr.size();
    while (h <  len/ 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < len; i++) {
            for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h) {
                std::swap(arr[j], arr[j - h]);
            }
        }
        h = h / 3;
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 7, 5, 7, 4};
    shell_sort(arr);
    for (auto &v : arr)
    {
        cout << v << " ";
    }
    return 0;
}