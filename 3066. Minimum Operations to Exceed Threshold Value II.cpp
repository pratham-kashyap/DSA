// You are given a 0-indexed integer array nums, and an integer k.
// In one operation, you will:
// - Take the two smallest integers x and y in nums.
// - Remove x and y from nums.
// - Add min(x, y) * 2 + max(x, y) anywhere in the array.
// - Note that you can only apply the described operation if nums contains at least two elements.
// Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap;
        for(int n:nums)
        minHeap.push(n);
        int count = 0;
        while(minHeap.top()<k){
            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();
            minHeap.push(x*2+y);
            count++;
        }
        return count;
    }
};
