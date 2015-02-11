/****************************************************
   file name: hdu5170.cpp
   author: Kal-iL
   creat time: Tue 10 Feb 2015 10:47:10 PM CST
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

const int MAXN = 0;

int a,b,c,d;

int main()
{
	while(~scanf("%d%d%d%d",&a,&b,&c,&d))
	{
		double t1 = 1.0 * b * log(1.0 * a);
		double t2 = 1.0 * d * log(1.0 * c);
		//注意精度问题
		if(t1-t2 > 1.0 * 1e-9)
			printf(">\n");
		else
			if(t2 - t1> 1.0 * 1e-9)
				printf("<\n");
			else
				printf("=\n");
	}
    return 0;
}
