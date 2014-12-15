#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int tot = 0;
	int i;
	for(i = 1;tot <= n; i ++)
	{
		tot += (1 + i) * i / 2;
		//printf("tot = %d i = %d ",tot ,i);
	}
	printf("%d\n",i - 2);
}