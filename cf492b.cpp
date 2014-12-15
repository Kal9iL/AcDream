#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 10;

int b[MAXN];

int main()
{
	int n,l;
	scanf("%d%d",&n,&l);
	for(int i = 0;i < n;i ++)
	{
		scanf("%d",&b[i]);
	}
	sort(b,b + n);
	double ans = 0;
	for(int i = 1;i < n;i ++)
	{
		double temp = 1.0 * (b[i] - b[i - 1]) / 2;
		if(ans < temp)
			ans = temp;
	}
	//printf(" %f\n",ans);
	if(1.0 * b[0] > ans)
		ans = 1.0 * b[0];
	if(1.0 * (l - b[n - 1]) > ans)
		ans = 1.0 * (l - b[n - 1]);
	printf("%.10f",ans);
}