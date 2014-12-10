/****************************************************
   file name: CF489A.cpp
   author: Kalis
   creat time: Tue 25 Nov 2014 09:58:09 PM CST
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

using namespace std;

const int MAXN = 3000 + 10;

int num[MAXN];
int ans[MAXN];
int a[MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i ++)
	{
		scanf("%d",&a[i]);
		num[i] = a[i];
	}
	sort(a,a + n);
	int tot = 0;
	memset(ans,-1 ,sizeof(ans));

	for(int i = 0;i < n;i ++)
	{
		if(num[i] != a[i])
		{
			tot ++;
			for(int j = i + 1; j < n;j ++)
			{	
				if(num[j] == a[i])
				{
					swap(num[i],num[j]);
					ans[i] = j;
					break;
				}
			}
		}
	}
	printf("%d\n",tot);
	for(int i = 0;i < n;i ++)
	{
		if(ans[i] != -1)
			printf("%d %d\n",i,ans[i]);
	}
    return 0;
}



//另一种方法

/****************************************************
//    file name: CF489A.cpp
//    author: Kalis
//    creat time: Tue 25 Nov 2014 09:58:09 PM CST
// ***************************************************/
// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <cmath>
// #include <algorithm>
// #include <map>
// #include <vector>
// #include <queue>

// using namespace std;

// const int MAXN = 3000 + 10;

// struct Node
// {
// 	int x;
// 	int pos;
// };

// map<int,int> mp;
// Node num[MAXN];
// int ans[MAXN];
// int a[MAXN];

// bool mycmp(Node a,Node b)
// {
// 	return a.x < b.x;
// }

// int main()
// {
// 	int n;
// 	scanf("%d",&n);
// 	for(int i = 0;i < n;i ++)
// 	{
// 		scanf("%d",&a[i]);
// 		num[i].x = a[i];
// 		num[i].pos = i;
// 	}
// 	sort(num,num + n,mycmp);
// 	for(int i = 0;i < n;i ++)
// 	{
// 		num[i].x += i;
// 		a[num[i].pos] = num[i].x;
// 		mp[num[i].x] = num[i].pos;
// 	}
// 	int tot = 0;

// 	memset(ans, -1,sizeof(ans));
// 	for(int i = 0;i < n;i ++)
// 	{
// 		if(a[i] != num[i].x)
// 		{
// 			tot ++;
// 			int pos = mp[num[i].x];
// 			mp[a[i]] = pos;
// 			swap(a[i],a[pos]);
// 			ans[i] = pos;		
// 		}
// 	}
// 	printf("%d\n",tot);
// 	for(int i = 0;i < n;i ++)
// 	{
// 		if(ans[i] != -1)
// 			printf("%d %d\n",i,ans[i]);
// 	}
//     return 0;
// }



