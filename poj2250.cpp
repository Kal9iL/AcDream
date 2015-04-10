/****************************************************
   file name: poj2250.cpp
   author: Kal-iL
   creat time: 2015年04月08日 星期三 18时58分17秒
***************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int MAXN = 50;

char s[MAXN];

int seq1[100 + 10];
int seq2[100 + 10];
int dp[100 + 10][100 + 10];
map<string,int> mp;

int K = 0;
int cont = 0;

int path[100 + 10][100 + 10];
int ans[100 + 10];
int len;

void print(int row,int col,int tot)
{
	if(row == 0)
		return;
	int flag = 1;
	for(int i = col;i >= 1;i --)
	{
		if(dp[row - 1][i - 1] + 1 == tot && path[row][i])
		{
			ans[len --] = seq1[row];
			print(row - 1,i - 1,tot - 1);
			flag = 0;
			break;
		}			
	}
	if(flag)
		print(row - 1,col,tot);
}

int main()
{
	while(~scanf("%s",s))
	{
		mp.clear();
		memset(seq1,0,sizeof(seq1));
		memset(seq2,0,sizeof(seq2));
		memset(ans,0,sizeof(ans));
		memset(path,0,sizeof(path));
		K = 1;
		cont = 1;
		mp[s] = K ++;
		seq1[cont ++] = mp[s]; 
		while(~scanf("%s",s) && s[0] != '#')
		{
			if(!mp[s])
				mp[s] = K ++;			
			seq1[cont ++] = mp[s];
			
		}
		int L1 = cont - 1;
		cont = 1;
		while(~scanf("%s",s) && s[0] != '#')
		{
			if(!mp[s])
				mp[s] = K ++;
			seq2[cont ++] = mp[s];
		}
		int L2 = cont - 1;
		memset(dp,0,sizeof(dp));
		for(int i = 1;i <= L1 + 1; i ++)
		{
			for(int j = 1; j <= L2 + 1; j ++)
			{
				if(seq1[i] == seq2[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					path[i][j] = 1;
				}
				else
				{
					if(dp[i - 1][j] > dp[i][j - 1])
					{
						dp[i][j] = dp[i - 1][j];
					}
					else
					{
						dp[i][j] = dp[i][j - 1];
					}
				}
			}
		}
		int sum = dp[L1][L2];
		len = sum - 1;
		for(int i = 1;i <= L2;i ++)
		{
			if(dp[L1][i] == sum)
			{
				print(L1,i,sum);
				break;
			}
		}
		for(int i = 0;i < sum; i ++)
		{
			for(map<string,int> :: iterator it = mp.begin();it != mp.end(); it ++)
			{
				if(it -> second == ans[i])
				{
					if(!i)
						cout << it -> first ;
					else
						cout << " " << it -> first ; 
				}
			}
		}
		printf("\n");
	}
    return 0;
}
