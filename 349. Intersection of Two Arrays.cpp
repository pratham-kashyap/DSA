// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n = nums1.size();
        int m = nums2.size();
        int i=0,j=0;
        vector<int> result;
        while(i<n && j<m)
        {
            if(nums1[i]==nums2[j])
            {
                int temp = nums1[i];
                result.push_back(temp);
                while(i<n && nums1[i]==temp){
                    i++;
                }
                while(j<m && nums2[j]==temp){
                    j++;
                }
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return result;
    }
};
