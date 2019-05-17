#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int size1 = nums1.size();
        int size2 = nums2.size();

        int tot = size1 + size2;

        if(tot & 1){
            return 1.0 * findk(nums1,0,nums2,0, tot / 2 + 1);
        }else{
            return 1.0 * (findk(nums1,0,nums2,0,tot / 2) + findk(nums1,0,nums2,0,tot/2 + 1)) / 2;
        }
    }
    int findk(vector<int> & nums1,int start1, vector<int> & nums2, int start2, int k){
        int size1 = nums1.size();
        int size2 = nums2.size();

        int s1 = size1 - start1;
        int s2 = size2 - start2;

        if(s1 > s2)
            return findk(nums2,start2,nums1,start1, k);

        if(s1 == 0)
            return nums2[start2 + k - 1];
        if(k == 1){
            return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
        }
        int split = min(s1, k / 2);

        if(nums1[start1 + split -1] > nums2[start2 + split - 1]){
            return findk(nums1,start1, nums2,start2 + split, k - split);
        }
        else{
            return findk(nums1,start1 + split, nums2,start2, k - split);
        }         
    }
};

int main()
{
    int arry1[2] = {1,3};
    int arry2[1] = {2};
    vector<int> nums1(arry1,arry1 + 2), nums2(arry2,arry2 + 1);
    Solution solution;
    double ans =  solution.findMedianSortedArrays(nums1,nums2);
    cout << ans << endl;
}
