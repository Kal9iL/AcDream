#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int dp[(1 << 21) + 10];
int ans[25];
int n;

int dfs(int s, int k)
{
    s -= (1 << k);
    if (dp[s] != -1)
        return dp[s];
    int p = s;
    for (int i = 2; i <= 20; i++)
    {
        if (! (s & (1 << i)))
        {
            if ((i + k <= 20) && (s & (1 << (i + k))))
            {
                s -= (1 << (i + k));
            }   
        }  
    }
    if (dp[s] != -1)
    {
        dp[p] = dp[s];
        return dp[s];
    }
    for (int i = 2; i <= 20; i++)
    {
        if (s & (1 << i))
        {
            if (dfs(s, i))
                dp[s] = 0;
        }
    }
    if (dp[s] == -1)
        dp[s] = 1;
    dp[p] = dp[s];
    return dp[s];
}


int main()
{
    int ics = 0;
    while (scanf("%d", &n) && n)
    {
        ics ++;
        memset(dp, -1, sizeof(dp));
        int init = 0;
        int temp;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            if (!(init & (1 << temp)))
                init += (1 << temp);
        }
        dp[0] = 1; //0表示负态，1表示胜态
        for (int i = 2; i <= 20; i++)
        {
            if (init & (1 << i))
            {
                dfs(init, i);
            }
        }
        int num_ans = 0;
        for (int i = 2; i <= 20; i++)
        {
            if ((init & (1 << i)) && dp[init - (1 << i)])
                ans[num_ans ++] = i;
        }
        printf("Test Case #%d\n", ics);
        if (num_ans == 0)
            printf("There's no winning move.");
        else
        {
            printf("The winning moves are:");
            for (int i = 0; i < num_ans; i++)
            {
                printf(" %d", ans[i]);
            }
        }
        printf("\n\n");
    }
}