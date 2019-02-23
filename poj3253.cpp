#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

# define ll long long

using namespace std;

priority_queue<ll, vector<ll>, greater<ll> > q;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
    {
        int temp;
        scanf("%d",&temp);
        q.push(temp);
    }
    ll ans = 0;
    while(q.size() >= 2)
    {
        int x1 = q.top();
        q.pop();
        int x2 = q.top();
        q.pop();
        ans += (x1 + x2);
        q.push(x1 + x2);
        
    }
    q.pop();
    printf("%lld\n",ans);
}