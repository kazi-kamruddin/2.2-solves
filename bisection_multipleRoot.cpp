#include<bits/stdc++.h>
using namespace std;

const double e = 0.000001;

double func(double x)
{
    int arr[] = {3,-8,2,5,-1};

    int sz = sizeof(arr) / sizeof(arr[0]);

    double ans = 0;

    for(int i = 0; i < sz; ++i){
        ans = ans * x + arr[i];
    }

    return ans;
}

void findRoots(double a, double b)
{
    double x1, x2, xr, ds;

    int rootCnt = 1;

    ds = 0.1;

    for(double i = a; i <= b; i += ds)
    {
        x1 = i;
        x2 = x1 + ds;

        if(func(x1) * func(x2) > 0)
        {
            // No root in this interval, continue to next interval
            continue;
        }

        do
        {
            xr = (x1 + x2) / 2.0;

            if(func(x1) * func(xr) < 0)
            {
                x2 = xr;
            }
            else
            {
                x1 = xr;
            }
        }
        while(fabs((x2 - x1) / x2) > e);

        if(x2 > b) {
            break;
        }

        cout << "[a, b]: " << "[" << i << ", " << (i + ds) << "]" << " Root Number: " << rootCnt << " Estimated Root: " << xr << endl;

        rootCnt++;
    }
}

int main()
{
    double a, b;
    a = -2.04, b = 2.04;

    findRoots(a, b);

    return 0;
}