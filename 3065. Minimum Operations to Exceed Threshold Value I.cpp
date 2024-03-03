// You are given a 0-indexed integer array nums, and an integer k.
// In one operation, you can remove one occurrence of the smallest element of nums.
// Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start<=end)
        {
            int m = start+(end-start)/2;
            if(nums[m]==k)
            {
                while(m>=0 && nums[m]==k)
                {
                    m--;
                }
                return m+1;
            }
            else if(nums[m]<k)
            start = m+1;
            else if(nums[m]>k)
            end = m-1;
        }
        return start;
    }
};
