/****************************************************
   file name: poj2046.cpp
   author: Kal-iL
   creat time: Thu 18 Dec 2014 09:57:27 PM CST
***************************************************/

//KMP做法，次题还可以用后缀数组做。

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

const int MAXN = 1000000 + 10;

char s[MAXN];
int next[MAXN];
int l;

void kmp()
{
	l = strlen(s);
	memset(next,0,sizeof(next));
	int j = -1;
	next[0] = -1;
	for(int i = 0;i < l;)
	{
		if(j == -1 || s[i] == s[j])
		{
			i ++;
			j ++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int main()
{
	while(~scanf("%s",s))
	{
		if(s[0] == '.')
			break;
		kmp();
		int ans = 1;
		if((l % (l - next[l]) == 0))
		{
			ans = (l /(l - next[l]));
		}
		printf("%d\n",ans);
	}
    return 0;
}
