#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;


int cor[200 + 10];

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T --)
    {
        memset(cor,0,sizeof(cor));
        scanf("%d",&n);
        int x,y;
        for(int i = 0;i < n;i ++)
        {
            scanf("%d%d",&x,&y);
            if(x > y)
                swap(x,y);
            for(int j = (x + 1) / 2; j <= (y + 1)/2; j ++ )
            {
                cor[j] ++ ;
            }
        }
        int ans = 0;
        for(int i = 1;i <= 200;i ++)
        {
            ans = max(ans,cor[i]);
        }
        printf("%d\n",ans * 10);
    }
}