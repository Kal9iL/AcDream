#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 10000 + 10;

double length[MAXN];

int main()
{
    int N, K;
    scanf("%d%d", &N, &K) ;
    double max_length = -1;
    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &length[i]);
        sum += length[i];
        if (max_length < length[i])
        {
            max_length = length[i];
        }
    }
    if (sum < 0.01 * K)
    {
        printf("0.00\n");
        return 0;
    }

    double l = 0.01, r = max_length;
    double mid;
    for(int j = 0;j < 200; j ++)
    {
        mid = (l + r) / 2;
        int tot = 0;
        for (int i = 0; i < N; i++)
        {
            tot += (int)(floor(length[i] / mid));
        }
        if (tot < K)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    printf("%.2f\n", floor(mid * 100) / 100);
    return 0;
}