#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> & nums) {
        vector< vector<int> > ans;

        sort(nums.begin(),nums.end());

        vector<int> res;
        vector<int> vis(nums.size(),0);
        dfs(nums,res,ans,vis,0);
        return ans;
    }

    void dfs(vector<int> & nums, vector<int> & res, vector<vector<int> > & ans, vector<int> & vis,int depth)
    {

        if(depth>= nums.size())
        {
            ans.push_back(res);
            return ;
        }
        for(int i = 0;i < nums.size(); i ++)
        {
            if(vis[i])
                continue;    

            if(i > 0 && nums[i] == nums[i - 1] && vis[i - 1] == 0)
            {
                continue;
            }
            res.push_back(nums[i]);
            vis[i] = 1;
            dfs(nums,res,ans,vis,depth + 1);
            res.pop_back();
            vis[i] = 0;
        }

    }
};


int main()
{
    int x[]={1,1,2,2};
    vector<int> a(x,x + 4);
    Solution b;
    vector<vector<int>> y = b.permuteUnique(a);
    for(auto it = y.begin();it != y.end();it ++)
    {
        vector<int> p = *it;
        for(int j = 0;j < p.size();j ++)
        {
            cout << p[j] << " ";
        }
        cout << endl;
    }

}