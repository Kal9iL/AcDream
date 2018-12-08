#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 5000000 + 10;

int main()
{
    int t;
    scanf("%d",&t);
    for(int ics = 1;ics <= t;ics ++)
    {
        int n;
        scanf("%d",&n);
        char buf[MAXN];
        scanf("%s",buf);
        int len = strlen(buf);
        int pre = buf[0] - '0';
        long long sum = 0;
        int half = len / 2;
        if (len & 1)
            half += 1;
        long long ans = 0;
        for(int i = 0;i < len;i ++)
        {
            if(i < half)
            {
                sum += buf[i] - '0';
            }
            else
            {
                if(sum > ans)
                {
                    ans = sum;
                }
                sum -= pre;
                pre = buf[i - half + 1] - '0';
                sum += (buf[i] - '0');
            }
        }
        if(sum > ans)
            ans = sum;
        printf("Case #%d: ",ics);
        printf("%lld\n",ans);
    }
}