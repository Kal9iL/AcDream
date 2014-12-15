#include <cstdio>
#include <iostream>
#include <algorithm>


using namespace std;

const int MAXN = 1e5 + 10;
int n,r;
long long avg;

struct Node
{
	long long a,b;
};

Node x[MAXN];

bool mycmp(Node p,Node q)
{
	if(p.b == q.b)
		return p.a < q.a; 
	return p.b < q.b;
}

int main()
{
	
	scanf("%d%d%d",&n,&r,&avg);
	//printf("  %d %d  \n",r,avg);
	long long sum = 0;
	for(int i = 0;i < n ;i ++)
	{
		scanf("%I64d%I64d",&x[i].a,&x[i].b);
		sum += x[i].a;
	}
	long long temp = avg * n;
	if(temp <= sum)
	{
		printf("0\n");
		return 0;
	}
	sort(x,x + n,mycmp);
	long long rem = temp - sum;
	//cout <<rem <<endl;
	long long ans = 0;
	for(int i = 0;i < n;i ++)
	{
		if((long long )r - x[i].a>= rem)
		{	
			ans += rem * x[i].b;
			break;
		}
		else
		{
			rem -= (r - x[i].a);
			ans += (r - x[i].a) * x[i].b;
		}
	}
	printf("%I64d\n",ans);

}