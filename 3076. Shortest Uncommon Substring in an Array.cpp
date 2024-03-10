// You are given an array arr of size n consisting of non-empty strings.

// Find a string array answer of size n such that:

// answer[i] is the shortest substring of arr[i] that does not occur as a substring in any other string in arr. 
// If multiple such substrings exist, answer[i] should be the lexicographically smallest.
// And if no such substring exists, answer[i] should be an empty string.
// Return the array answer.

 class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        map<string,set<int>> mp;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            int l = arr[i].length();
            int j = 0;
            while(j<l)
            {
                int k = 1;
                while(k<=l)
                {
                    mp[arr[i].substr(j,k)].insert(i);
                    k++;
                }
                j++;
            }
        } 
        vector<string> result(n,"");
        for(auto it:mp)
        {
            if(it.second.size()==1)
            {
                if(result[*it.second.begin()]=="" || it.first.length()<result[*it.second.begin()].length())
                result[*it.second.begin()] = it.first;
            }
        }
        return result;
    }
};
