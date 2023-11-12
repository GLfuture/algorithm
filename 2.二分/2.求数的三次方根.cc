/*
给定一个浮点数 n
，求它的三次方根。

输入格式
共一行，包含一个浮点数 n
。

输出格式
共一行，包含一个浮点数，表示问题的解。

注意，结果保留 6
 位小数。

数据范围
−10000≤n≤10000
*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

bool check(double num , double t)
{
    if(pow(t,3) <= num) return true;
    return false;
}


int main()
{

    double num;
    cin >> num;
    
    double l = -10000,r = 10000;
    while(r-l > 1e-8)
    {
        double mid = (l + r ) / 2;
        if(check(num,mid)) l = mid;
        else r = mid;
    }
    cout <<std::fixed << std::setprecision(6) << l << endl;
    return 0;
}