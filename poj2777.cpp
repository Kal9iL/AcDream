#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 10;

struct Node
{
	int l,r;
	int col;
}tree[MAXN * 4];

int L,T,O;
char ch[2];
int a,b,c;
int cnt;

int vis[35];

void build(int x,int y,int i)
{
	tree[i].l = x;
	tree[i].r = y;
	tree[i].col = 1;
	if(x == y)
		return ;
	int mid = (x + y) >> 1;
	build(x, mid,i + i);
	build(mid + 1,y ,i + i + 1);
}

void update(int x,int y,int i,int cl)
{
	int l = tree[i].l;
	int r = tree[i].r;
	int mid = (l + r) >> 1;
	if(l == x && r == y)
	{
		tree[i].col = cl;
		return;
	}
	if(tree[i].col != -1)
	{
		tree[i + i].col = tree[i + i + 1].col = tree[i].col;
		tree[i].col = -1;
	}
	if(x <= mid)
		update(x,min(y,mid),i + i,cl);
	if(y > mid)
		update(max(x,mid + 1),y,i + i + 1,cl);

	if(tree[i + i].col == tree[i + i + 1].col)
		tree[i].col = tree[i + i].col;

}

void  query(int x,int y,int i)
{
	int l = tree[i].l;
	int r = tree[i].r;
	int mid = (l + r) >> 1;
	// if(l == x && r == y)
	// {
	// 	if(tree[i].col != -1)
	// 	{
	// 		if(!vis[tree[i].col])
	// 		{
	// 			cnt ++;
	// 			vis[tree[i].col] = 1;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		query(l,mid,i + i);
	// 		query(mid + 1, r ,i + i + 1);
	// 	}
	// 	return ;
	// }
	// if(tree[i].col != -1)
	// {
	// 	tree[i + i].col = tree[i + i + 1]. col = tree[i].col;
	// }

	if(tree[i].col != -1)
	{
		if(!vis[tree[i].col])
		{
			cnt ++;
			vis[tree[i].col] = 1;
		}
		return ;
	}
	if(x <= mid)
		query(x,min(y,mid),i + i);
	if(y > mid)
		query(max(mid + 1,x),y, i + i + 1);
}



int main()
{
	scanf("%d%d%d",&L,&T,&O);
	build(1,L,1);
	for(int i = 0;i < O ;i ++)
	{
		scanf("%s",ch);
		if(ch[0] == 'C')
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a > b)
				swap(a,b);
			update(a,b,1,c);
		}
		else
		{
			scanf("%d%d",&a,&b);
			if(a > b)
				swap(a,b);
			memset(vis,0,sizeof(vis));
			cnt = 0;
			query(a,b,1);
			printf("%d\n",cnt);
		}
	}
	return 0;
}
