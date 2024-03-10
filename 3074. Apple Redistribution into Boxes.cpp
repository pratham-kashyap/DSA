// You are given an array apple of size n and an array capacity of size m.

// There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

// Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

// Note that, apples from the same pack can be distributed into different boxes.

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.begin(),capacity.end(),greater<int>());
        int n = capacity.size();
        int newsum = 0;
        int i=0;
        while(newsum<sum)
        {
            newsum += capacity[i];
            i++;
        }
        return i;
    }
};
