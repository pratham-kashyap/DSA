// You are given an array nums consisting of positive integers.

// Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

// The frequency of an element is the number of occurrences of that element in the array.

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        mp[nums[i]]++;
        int m = 0;
        int c = 0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>m)
            {
                m = it->second;
                c = 0;
            }
            if(it->second == m)
            c += m;
        }
        return c;
    }
};
