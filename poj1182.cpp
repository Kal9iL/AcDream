#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 50000 + 10;

int n,k,d,x,y;
int f[MAXN];
int r[MAXN];

void init()
{
    for(int i = 0;i <= n;i ++)
    {
        f[i] = i;
        r[i] = 0;
    }
}

int find_f(int a)
{
    if(a == f[a])
        return a;
    int fa = find_f(f[a]);
    r[a] = (r[a] + r[f[a]]) % 3;
    return f[a] = fa; 
}

int Union(int d,int a,int b)
{
    int fa = find_f(a);
    int fb = find_f(b);

    if(fa == fb)
    {
        if((r[a] - r[b] + 3) % 3 == (d - 1))
            return 0;
        else
            return 1;
    }
    else
    {
        f[fa] = fb;
        r[fa] = ((r[b] + d - 1) - r[a] + 9 ) % 3;
    }
    return 0;
}

int main()
{
    scanf("%d%d",&n,&k);
    init();
    int ans = 0;
    for(int i = 0;i < k;i ++)
    {
        scanf("%d%d%d",&d,&x,&y);
        if(d == 2 && x == y)
        {
            ans ++;
            continue;
        }
        if(x > n || y > n)
        {
            ans ++;
            continue;
        }
        ans += Union(d,x,y);
    }
    printf("%d\n",ans);
}


/*见《挑战程序设计竞赛》的另一种解法，看不懂。*/
