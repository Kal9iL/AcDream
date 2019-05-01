#include <vector>
#include <unordered_map>
#include <iostream>


using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int length = nums.size();
        for(int i = 0;i < length; i ++){
            m[nums[i]] = -1;
        }        
        int ans = 0;
        for(int i = 0;i < length; i ++){
            search(m,nums[i]);
            ans = max(ans,m[nums[i]]);
        }
        return ans;
    }

    void search(unordered_map<int,int> & m,int num){
        if(m[num] >= 0)
            return; 
        else{
            search(m, num - 1);
            m[num] = m[num - 1] + 1;
        }
    }
};

class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        unordered_map<int,bool> used;
        for(auto i: nums)
            used[i] = false;
        int longest = 0;
        for(auto i:nums){
            if(used[i])
                continue;
            int length = 1;
            used[i] = true;

            for(int j = i + 1; used.find(j) != used.end(); ++j){
                used[j] = true;
                ++ length;
            }
            for(int j = i - 1; used.find(j) != used.end(); -- j){
                used[j] = true;
                ++ length;
            }
            longest = max(longest,length);
            
        }
        return longest;
    }
};

int main()
{
    int data[100];
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n; i++){
        scanf("%d",&data[i]);
    }
    vector<int> p(data,data + n);
    int size = p.size();
    for(int i = 0;i< size; i ++)
        cout << p[i] << " ";
    cout << endl;
    Solution1 sol;
    cout << sol.longestConsecutive(p);

}