// You are given a sorted unique integer array nums.
// A range [a,b] is the set of all integers from a to b (inclusive).
// Return the smallest sorted list of ranges that cover all the numbers in the array exactly.
// That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
// Each range [a,b] in the list should be output as:
// "a->b" if a != b
// "a" if a == b

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        string temp = "";
        for(int i=0;i<n;i++)
        {
            int flag = i;
            temp = to_string(nums[i]);
            while((i+1)<n && ((long long)nums[i+1]-(long long)nums[i])==1LL)
            {
                i++;
            }
            if(i>flag)
            temp += "->"+to_string(nums[i]);

            result.push_back(temp);
        }
        return result;
    }
};
