#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAXN 1010

double s[MAXN];
int a[MAXN],b[MAXN];

int n;

int main()
{
	while(cin>>n)
  	{
    	int i,j;
    	for(i = 1;i <= n;i++)
      		scanf("%lf",&s[i]);
    	a[1]=1;
    	for(i = 2;i <= n;i ++)//从头开始计算最长的递增序列 
    	{
      		a[i]=1;
      		for(j=1;j < i;j ++)
      		{
        		if(s[i] > s[j]&& a[j] >= a[i])
          		a[i] = a[j] + 1;
      		}
        }
        b[n]=1;
    	for(i = n - 1;i >= 1;i --)//从尾部计算最长的递增序列 
    	{
      		b[i]=1;
      		for(j=n;j>i;j--)
      		{
        		if(s[i] > s[j] && b[j] >= b[i])
          		b[i] = b[j]+1;
      		}
    	}
    	int max=-100000;//初始化max
    	for(i=1;i<=n;i++)
    	{
      		for(j=i+1;j<=n;j++)
      		{
        		if(a[i]+b[j]>max)
        		max=a[i]+b[j];
      		}
    	}
    	printf("%d\n",n-max);
  	}
 	return 0;
}