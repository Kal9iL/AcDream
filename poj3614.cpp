#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int c,l;

struct Cow
{
    int minspf,maxspf;
};

struct Lotion
{
    int spf,cover;
};

Cow cow[2500];
Lotion lotion[2500];
int vis[2500];

bool cmpcow(Cow a,Cow b)
{
    if(a.maxspf == b.maxspf)
        return a.minspf < b.minspf;
    return a.maxspf < b.maxspf;
}


bool cmplotion(Lotion a, Lotion b)
{
    return a.spf < b.spf;
}
int main()
{
    scanf("%d%d",&c,&l);
    for(int i = 0 ;i < c;i ++)
    {
        scanf("%d%d",&cow[i].minspf,&cow[i].maxspf);
    }
    int k = 0;
    for(int i = 0;i < l;i ++)
    {
        int sp,co;
        scanf("%d%d",&sp,&co);
        if(co > 0)
        {
            lotion[k].spf = sp;
            lotion[k].cover = co;
            k ++;
        }    
    }
    l = k;
    sort(cow,cow + c,cmpcow);
    sort(lotion,lotion + l, cmplotion);

    
    memset(vis,0,sizeof(vis));
    int ans = 0;
    for(int i = 0; i < l; i ++)
    {
        for(int j = 0; j < c; j ++)
        {
            if(vis[j] || lotion[i].cover <= 0)
                continue;
            if(cow[j].minspf <= lotion[i].spf && cow[j].maxspf >= lotion[i].spf)
            {
                ans ++;
                lotion[i].cover --;
                vis[j] = 1;
            }
        }
    }
    printf("%d\n",ans);
}