#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 10;

int rate[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    for(int ics = 1;ics <= t; ics ++)
    {
        int n,p;
        scanf("%d%d",&n,&p);
        for(int i = 0;i < n;i ++)
        {
            scanf("%d",&rate[i]);
        }
        sort(rate,rate + n);
        int tot = 0;
        for(int i = 0;i < p; i ++)
        {
            tot += rate[i];
        }
        int ans = rate[p - 1] * p - tot;
        for(int i = p;i < n; i ++)
        {
            tot += rate[i];
            tot -= rate[i - p];
            int temp = rate[i] * p - tot;
            if(temp < ans)
            {
                ans = temp;
            }
        }
        printf("Case #%d: %d\n",ics,ans);
    }    
}