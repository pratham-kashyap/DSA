// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int limit = nums[0];
        int n = nums.size()-1;
        for(int i=0;i<=limit;i++)
        {
            nums[i] = nums[i]+i;
            if(nums[i]>=n)
            return true;
            if(nums[i]>limit)
            limit = nums[i];
        }
        return false;
    }
};
