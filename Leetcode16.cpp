#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int min_gap = INT_MAX;
        int size = nums.size();
        sort(nums.begin(),nums.end());
        for(auto a = nums.begin(); a != prev(nums.end(),2); ++ a){
            auto b = next(a);
            auto c = prev(nums.end());
            while(b < c){
                const int sum = *a + *b + *c;
                const int gap = abs(sum -target);
                if(gap < min_gap){
                    result = sum;
                    min_gap = gap;
                }
                if(sum < target)
                    ++b;
                else 
                    --c;
            }
        }
        return result;    
    }
    
};

int main()
{
    int arr[6] = {0,11,12,15,18,20};
    vector<int> nums(arr,arr + 6);
    Solution solution ;
    cout <<     solution.threeSumClosest(nums,30) << endl;
    return 0; 
}
