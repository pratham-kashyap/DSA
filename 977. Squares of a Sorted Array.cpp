// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg;
        vector<int> pos;
        vector<int> ans;
        int l1 = -1, l2 = -1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                neg.push_back(nums[i]*nums[i]);
                l1++;
            }
            else
            {
                pos.push_back(nums[i]*nums[i]);
                l2++;
            }
        }
        int i = 0;
        while(l1>=0 && i<=l2)
        {
            if(neg[l1]<pos[i])
                ans.push_back(neg[l1--]);
            else
                ans.push_back(pos[i++]);
        }
        while(l1>=0)
        {
            ans.push_back(neg[l1--]);
        }
        while(i<=l2)
        {
            ans.push_back(pos[i++]);
        }
        return ans;
    }
};
