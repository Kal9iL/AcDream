#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> & nums) {
        set< vector<int> > ans;

        vector<int> res;
        // vector<int> vis(nums.size(),0);

        //dfs(nums,res,ans,vis,0);
        permute(ans,nums,0);
        return vector<vector<int>> (ans.begin(),ans.end());
    }

    void permute(set<vector<int> > & ans,vector<int> & nums, int start){
        if( start >= nums.size())
            ans.insert(nums);
        for(int i = start; i < nums.size();i ++){
            swap(nums[start],nums[i]);
            permute(ans,nums,start + 1);
            swap(nums[start],nums[i]);
        }
    }

};


int main()
{

}