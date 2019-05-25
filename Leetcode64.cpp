#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    
        int r = grid.size();
        if(r <= 0)
            return 0;
        int c = grid[0].size();
        int ** dp = new int * [r + 10];
        for(int i = 0;i < r + 10; i ++){
            dp[i] = new int[c + 10];
            memset(dp[i],-1,sizeof(int) * (c + 10));
        }
        
        dp[0][0] = grid[0][0];
        for(int i = 0;i < r + 10; i ++){
            for(int j = 0; j< c + 10; j ++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        
        return search(dp,grid,r - 1,c - 1);
        
    }
    
    int search(int ** dp, vector<vector<int>> & grid, int i,int j){
        
        if(i < 0 || j < 0)
            return INT_MAX;
        if(dp[i][j] >= 0)
            return dp[i][j];
        dp[i][j] = min(search(dp,grid,i - 1,j), search(dp,grid,i,j - 1)) + grid[i][j];
        return dp[i][j];
    }
    
    
};

int main()
{
    vector<vector<int> > data;
    data.push_back({1,3,1});
    data.push_back({1,5,1});
    data.push_back({4,2,1});

    Solution sol;
    int ans = sol.minPathSum(data);
    cout << ans << endl;

}