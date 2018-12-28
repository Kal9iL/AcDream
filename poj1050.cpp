#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 101;
int N;
int arr[MAXN][MAXN];
int sumcol[MAXN][MAXN];

int main()
{
    scanf("%d",&N);
    for(int i = 1;i <= N; i ++)
    {
        for(int j = 1;j <= N; j ++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    
    memset(sumcol,0,sizeof(sumcol));

    for(int i = 1;i <= N;i ++)
    {
        for(int j = 1; j <= N;j ++)
        {
            sumcol[i][j] = sumcol[i - 1][j] + arr[i][j];
        }
    }
    
    int ans = 0;
    for(int x = 0; x <= N; x ++)
    {
        for(int y = 1; x + y <= N; y ++)
        {
            int sum = 0;
            for(int k = 1; k <= N; k ++)
            {
                sum += (sumcol[x + y][k] - sumcol[x][k]);
                if( sum > ans)
                    ans = sum;
                if(sum < 0)
                    sum = 0;
            }
        }
    }
    printf("%d\n",ans);
}
