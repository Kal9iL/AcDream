#include <stdio.h>

#define MAXN 1010
#define MAXM 20010

const int INF = (1 << 24);

struct node{
    int u, v, w;
}edge[MAXM];

int n, m, top, d[MAXN];

void Init()
{
    top = 0;
}

void sort(int *a, int *b)
{
    int t;
    if(*a > *b)
    {
        t = *a; *a = *b; *b = t;
    }
}

void add(int u, int v, int w)
{
    edge[top].u = u;
    edge[top].v = v;
    edge[top++].w = w;
}

int bellman_ford()
{
    int i, j, u, v, w;

    for(i = 1; i <= n; i ++) 
        d[i] = INF;

    d[1] = 0;

    for(i = 1; i < n; i ++)
    {
        for(j = 0; j < m; j ++)
        {
            u = edge[j].u;
            v = edge[j].v;
            w = edge[j].w;
            if(d[u] < INF && d[u] + w < d[v])
            {
                d[v] = d[u] + w;
            }
            for(int k = 1; k <= n;k ++)
            {
                printf("%d ",d[k]);
            }
            printf("\n");

        }
    }

    for(j=0; j<m; j++)
    { 
        //检测负环
        u = edge[j].u;
        v = edge[j].v;
        w = edge[j].w;
        if(d[u] < INF && d[u] + w < d[v])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int ml, md, i, u, v, w;

    scanf("%d %d %d", &n, &ml, &md);

    Init();

    m = ml + md;

    for(i = 0; i<ml; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        sort(&u, &v);
        add(u, v, w);
    }

    for(i=0; i < md; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        sort(&u, &v);
        add(v, u, -w);
    }
    for(int i = 0;i < m ;i ++)
        printf("%d %d %d\n",edge[i].u,edge[i].v,edge[i].w);
    

    if(bellman_ford() == 0)
    {
        printf("-1\n");
    }
    else if(d[n] == INF)
    {
        printf("-2\n");
    }
    else 
        printf("%d\n", d[n]);

    return 0;
}