// You are given a binary string s that contains at least one '1'.
// You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
// Return a string representing the maximum odd binary number that can be created from the given combination.
// Note that the resulting string can have leading zeros.

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count0 = 0;
        int n = s.length();
        for(int i=0;i<n;i++)
        if(s[i] == '0')
        count0++;
        string ans = "";
        for(int i=1;i<n-count0;i++)
        ans += "1";
        for(int i=1;i<=count0;i++)
        ans += "0";
        return ans+"1";
    }
};
