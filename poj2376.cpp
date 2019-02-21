#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Cow
{
    int start,end;
};

Cow cow[25000 + 10];

bool cmp(Cow a,Cow b)
{
    if(a.start ==  b.start)
        return a.end < b.end;
    return a.start < b.start;
}


int main()
{
    int N,T;
    scanf("%d%d",&N,&T);
    for(int i = 0;i < N;i ++)
    {
        scanf("%d%d",&cow[i].start,&cow[i].end);
    }
    sort(cow,cow + N,cmp);
    int curpos = 0;
    int fur = 0;
    int nextstep = 0;
    int flag = 0;
    int ans = 0;
    while(curpos < N)
    {
        nextstep = curpos;
        int findnext = false;
        while(curpos < N && cow[curpos].start <= fur + 1)
        {
            if(cow[curpos].end >= cow[nextstep].end)
            {
                nextstep = curpos;
                findnext = true;
            }
            curpos ++;
        }
        if(!findnext)
            break;
        fur = cow[nextstep].end;
        ans ++;
        if(fur >= T)
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        printf("%d\n",ans);
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}