#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m;
int dp[20 + 10][8000 + 20];
int path[20 + 10][8000 + 20];

int main()
{
    int count = 0;
    while(scanf("%d%d",&n,&m) && (m!= 0 && n != 0))
    {
        count ++;
        //int pi,di;
        memset(dp,-1,sizeof(dp));
        memset(path,-1,sizeof(path));
        int pi[200 + 10],di[200 + 10];
        memset(pi,0,sizeof(pi));
        memset(di,0,sizeof(di));
        for(int i = 1;i <= n;i ++)
        {
            scanf("%d%d",&pi[i],&di[i]);
        }
        dp[0][4010] = 0;

        for(int i = 1;i <= m; i ++)
        {    
            for(int j = 1;j <= n; j ++)
            {
                for(int k = 0; k < 8020; k ++ )
                {
                    if(dp[i - 1][k] >= 0)
                    {
                        if(dp[i][k + (pi[j] - di[j])] < dp[i - 1][k] + di[j] + pi[j])
                        {
                            int flag = false;
                            int startk = k;
                            int counti = 0;
                            int temp = path[i - 1 - counti][k];
                            while(temp != -1)
                            {
                                //cout << temp << endl;
                                if(temp == j)
                                {
                                    flag = true;
                                    break;
                                }
                                counti ++;
                                temp = path[i - 1 - counti][startk = startk - (pi[temp] - di[temp])];
                            }
                            if(!flag)
                            {
                                
                                dp[i][k + (pi[j] - di[j])] =  dp[i - 1][k] + di[j] + pi[j];
                                path[i][k + (pi[j] - di[j])] = j;
                                //printf("path[%d][%d] = %d  ",i,pi[j] - di[j], j); 
                                //printf("dp[%d][%d] = %d\n",i,pi[j] - di[j],dp[i][k + (pi[j] -di[j])]);
                            }
                        }
                    }
                }
            }
        }
       // printf("after dp\n");
        int pro = 0,def = 0;
        int ans_list[20 + 10];
        int counti = 0;
        for(int i = 0;i <= 4010;i ++)
        {
            if(dp[m][4010 - i] >= 0 || dp[m][4010 + i] >= 0)
            {
                if(dp[m][4010 - i] > dp[m][4010 + i])
                {
                    int temp = path[m][4010 - i];
                    int startk = 4010 - i;
                    //int counti = 0;
                    //int temp = path[m - counti][startk];
                    //cout << "temp = " << temp << " " ;
                    while(temp != -1)
                    {
                        pro += pi[temp];
                        def += di[temp];
                        ans_list[counti] = temp;
                        counti ++;
                        temp = path[m - counti ][startk = startk - (pi[temp] - di[temp])];
                      //  cout << temp << " ";
                    }
                    //cout << endl;
                }
                else
                {
                    int temp = path[m][4010 + i];
                    int startk = 4010 + i;
                    //int counti = 0;
                    //int temp = path[m - counti][startk];
                    //cout << "temp = " << temp << " " ;
                    while(temp != -1)
                    {
                        pro += pi[temp];
                        def += di[temp];
                        ans_list[counti] = temp;
                        counti ++;
                        temp = path[m - counti ][startk = startk - (pi[temp] - di[temp])];
                      //  cout << temp << " ";
                    }
                    //cout << endl;
                }
                break;
            }
        }
        //cout << counti << endl;
        printf("Jury #%d\n",count);
        printf("Best jury has value %d for prosecution and value %d for defence:\n",pro,def);
        sort(ans_list,ans_list + m);
        for(int i = 0;i <  m;i ++)
            printf(" %d",ans_list[i]);
        printf("\n");
        //printf("%d\n",ans_value);
    }
    return 0;
}

