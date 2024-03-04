// You are given a 1-indexed array of distinct integers nums of length n.

// You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:

// If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1. Otherwise, append nums[i] to arr2.
// The array result is formed by concatenating the arrays arr1 and arr2. For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result = [1,2,3,4,5,6].

// Return the array result.

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a1;
        vector<int> a2;
        int n = nums.size();
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        for(int i=2,j=0,k=0;i<n;i++)
        {
            if(a1[j]>a2[k])
            {
                a1.push_back(nums[i]);
                j++;
            }
            else
            {
                a2.push_back(nums[i]);
                k++;
            }
        }
        a1.insert(a1.end(),a2.begin(),a2.end());
        return a1;
    }
};
