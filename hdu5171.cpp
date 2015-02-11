/****************************************************
   file name: hdu5171.cpp
   author: Kal-iL
   creat time: Tue 10 Feb 2015 11:04:47 PM CST
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

const int MAXN = 100000 + 10;
#define  mod 10000007
int n,k;
long long sum;
const int Max = 10;

struct Mat
{
    long long mat[Max][Max];
    int row,col;
    Mat(){}
    Mat(bool e,int _row = Max,int _col = Max)
    {

    	row = _row;
    	col = _col;
    	if(e)
    		for(int i = 0;i < Max;i ++)
    			for(int j = 0; j < Max; j ++)
    				mat[i][j] = (i == j);
    	else
    		memset(mat,0,sizeof(mat));
    }
};

Mat operator * (Mat a,Mat b)  
{
	Mat c;  
	int row = a.row;
	int col = b.col;
	int t = a.col;
	for (int i = 0; i < row; i ++)  
	{  
        for (int j = 0; j < col; j ++)  
        {  
            c.mat[i][j] = 0;  
            for(int k = 0;k < t ; k ++)  
                c.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % mod;  
        }  
    }  
    c.row = row;
    c.col = col;
    return c;  
}

Mat operator + (Mat a,Mat b)  
{  
	Mat c;  
	int row = a.row;
	int col = a.col;
	for (int i = 0;i < row; i ++)  
	{  
		for(int j = 0; j < col ; j++)  
		    c.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % mod;  
	}  
	c.row = row;
	c.col = col;
	return c;
}

Mat operator ^ (Mat a,int x)  
{  
    Mat p(true,3,3);
    Mat q = a;  
    while(x)  
    {  
        if(x & 1)  
            p = p * q;  
        x >>= 1;  
        q = q * q;  
     }  
     return p;  
 }

int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		int m1 = -1;
		int m2 = -1;
		int t;
		sum = 0;
		for(int i = 0;i < n;i ++)
		{
			scanf("%d",&t);
			t = t % mod;
			sum += t;
			sum = sum % mod;
			if(t > m1)
			{
				m2 = m1;
				m1 = t;
				
			}
			else
			{
				if(t > m2)
					m2 = t;
			}
		}
		Mat to(false,3,3);
		to.mat[0][0] = to.mat[0][1] = to.mat[0][2] = 1;
		to.mat[1][0] = 0;
		to.mat[1][1] = to.mat[1][2] = 1;
		to.mat[2][0] = to.mat[2][2] = 0;
		to.mat[2][1] = 1;
		Mat mul = to ^ k;
		Mat bas(false,3,1);
		bas.mat[0][0] = (m1 + m2) % mod;
		bas.mat[1][0] = m1;
		bas.mat[2][0] = m2;

		Mat ans = mul * bas;
		printf("%lld\n",(ans.mat[0][0] + (long long) (sum - m1 - m2)) % mod);
	}
    return 0;
}