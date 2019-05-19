class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0;i <= size - 4; i ++){
            if(i > 0&& nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1;j <= size - 3; j ++){
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1,r = size - 1;
                while(l < r){
                    if(nums[l] + nums[r] == target - nums[i] - nums[j]){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        int val = nums[l];
                        while(l < r && nums[l] == val){
                            l ++;
                        }
                    }else{
                        if(nums[l] + nums[r] > target - nums[i] - nums[j]){
                            r --;
                        }else{
                            l ++;
                        }
                        
                    }
                }
            }
        }
        return ans;
        
    }
};