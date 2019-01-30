#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n;
int src,des;
char cmd1[10],cmd2[10];

char quit[] = "quit";
char mv[] = "move";
char pile[] = "pile";
char onto[] = "onto";
char over[] = "over";

int pilepos[30];
int stackpos[30];
int ne[30];


void return_back(int x)
{
    for(int i = 0;i < n;i ++)
    {
        if(pilepos[i] == pilepos[x] && stackpos[i] > stackpos[x])
        {
            pilepos[i] = i;
            stackpos[i] = 1;
            ne[i] = -1;
        }
    }
    ne[x] = -1;
}

int find_top(int x)
{
    int max_top = -1;
    for(int i = 0;i < n;i ++)
    {
        if(pilepos[i] == pilepos[x])
        {
            max_top = max(stackpos[i],max_top);
        }
    }
    return max_top;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n; i ++)
    {
        pilepos[i] = i;
        stackpos[i] = 1;
        ne[i] = -1;
    }

    while(true)
    {
        scanf("%s",cmd1);
        if(strcmp(quit,cmd1) == 0)
            break;
        scanf("%d",&src);
        scanf("%s",cmd2);
        scanf("%d",&des);
        if(src == des)
            continue;
        if(strcmp(cmd1,mv) == 0 && strcmp(cmd2,onto) == 0)
        {
            return_back(src);
            return_back(des);
            pilepos[src] = pilepos[des];
            stackpos[src] = stackpos[des] + 1;
            ne[des] = src;
            ne[src] = -1;
        }
        if(strcmp(cmd1,mv) == 0 && strcmp(cmd2,over) == 0)
        {
            return_back(src);
            pilepos[src] = pilepos[des];
            int cur = des;
            while(ne[cur] >= 0)
            {
                cur = ne[cur];
            }
            ne[cur] = src;
            int max_top = stackpos[cur];
            
            ne[src] = -1;
            stackpos[src] = max_top + 1;
        }
        if(strcmp(cmd1,pile) == 0 && strcmp(cmd2,onto) == 0)
        {
            return_back(des);
            int cur = pilepos[src];
           if(cur != src)
            {
                while(ne[cur] != src)
                {
                    cur = ne[cur];
                }
                ne[cur] = -1;
            }
            int max_top = find_top(des);
            cur = src;
            while(cur >= 0)
            {
                pilepos[cur] = pilepos[des];
                stackpos[cur] = ++max_top; 
                cur = ne[cur];
            }
            ne[des] = src;
        }
        if(strcmp(cmd1,pile) == 0 && strcmp(cmd2,over) == 0)
        {
            if(pilepos[src] == pilepos[des])
                continue;
            int cur = des;
            while(ne[cur] >= 0)
            {
                cur = ne[cur];
            }
            ne[cur] = src;
            cur = pilepos[src];
            if(cur != src)
            {
                while(ne[cur] != src)
                {
                    cur = ne[cur];
                }
                ne[cur] = -1;
            }

            
            int max_top = stackpos[cur];
            cur = src;
            while(cur >= 0)
            {
                pilepos[cur] = pilepos[des];
                stackpos[cur] = ++ max_top;
                cur = ne[cur];
            }
            
        }
    }
    for(int i = 0;i < n;i ++)
    {
        printf("%d:",i);
        if(pilepos[i] == i)
        {
            int cur = i;
            while(cur >= 0)
            {
                printf(" %d",cur);
                cur = ne[cur];
            }
        }
        printf("\n");        
    }
    return 0;
}