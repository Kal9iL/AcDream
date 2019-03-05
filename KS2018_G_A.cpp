#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int t,n;

int arr[7000 + 10];

map<int ,int> hash_map;

int main()
{
    scanf("%d",&t);
    for(int ics = 0; ics < t; ics ++)
    {
        hash_map.clear();
        scanf("%d",&n);
        int count0 = 0;
        int k = 0;
        for(int i = 0;i < n;i ++)
        {
            int temp;
            scanf("%d",&temp);
            if(temp == 0)
            {
                count0 ++;
                continue;
            }
            else
                arr[k ++] = temp;
        }
        long long ans = 0;
        if(count0 > 0)
        {
            ans += ((long long)count0 * (long long)(count0 - 1) * (long long)(count0 - 2) / 6);
            ans += ((long long)count0 *(long long) (count0 - 1) / 2 *(long long) (n - count0));
        }
        sort(arr,arr + k);
        
        int max_num = arr[k - 1];
        for(int i = k - 1;i >= 0 ;i --)
        {
            for(int j = i - 1; j >= 0;j --)
            {
                if(max_num * 2 / arr[i] < arr[j])
                    continue;
                else
                {
                    int product =  arr[i] *  arr[j];
                    ans += hash_map[product];
                }
            }
            hash_map[arr[i]] ++;
        }
        printf("Case #%d: %lld\n",ics + 1,ans);

    }
}