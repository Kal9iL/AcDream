#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        ans.clear();
        if(nums.size()< 3 )
            return ans;
        map<int,int> count;
        count.clear();
        int length = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i < length ;i ++){
            count[nums[i]] ++;
        }
        int prei = nums[0] - 1;
        for(int i = 0;i < length - 1;i ++){
            if(nums[i] >= 0){
                break;
            }
            if(nums[i] == prei){
                continue;
            }else{
                prei = nums[i];
            }
            int prej = nums[i + 1] - 1;
            for(int j = i + 1;j < length; j ++){
                if(nums[j] > 0){
                    break;
                }
                if(nums[j] == prej){
                    continue;
                }else{
                    prej = nums[j];
                }
                int temp = -(nums[i] + nums[j]);
                if(count[temp] > 0)
                {
                    int x[] = {nums[i],nums[j],temp};
                    vector<int> a(x,x + 3);
                    ans.push_back(a);
                }
            }
        }

        prei = nums[length - 1] - 1;
        for(int i = length - 1; i > 0; i --){
            if(nums[i] <= 0){
                break;
            }
            if(nums[i] == prei){
                continue;
            }else{
                prei = nums[i];
            }
            int prej = nums[i - 1] - 1;
            for(int j = i - 1;j >= 0; j --){
                if(nums[j] <= 0){
                    break;
                }
                if(nums[j] == prej){
                    continue;
                }else{
                    prej = nums[j];
                }
                int temp = -(nums[i] + nums[j]);
                if(count[temp] > 0)
                {
                    int x[] = {nums[i],nums[j],temp};
                    vector<int> a(x,x + 3);
                    ans.push_back(a);
                }
            }
        }
        if(count[0] >= 3){
            vector<int> a(3,0);
            ans.push_back(a);
        }
        return ans;
    }
};

int main()
{
    int x[] = {-4,-2,-1};
    vector<int> t(x,x + 3);
    Solution solution;
    vector<vector<int> > ans = solution.threeSum(t);
    if(ans.size() > 0)
    for(int i = ans.size();i >0 ; i -- )
    {
        printf("%d %d %d\n",ans[i - 1][0],ans[i - 1][1],ans[i - 1][2]);
    }
    else
    printf("Empty\n");
    return 0;
}