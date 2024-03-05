// Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:

// Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
// Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
// The prefix and the suffix should not intersect at any index.
// The characters from the prefix and suffix must be the same.
// Delete both the prefix and the suffix.
// Return the minimum length of s after performing the above operation any number of times (possibly zero times).

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int l = 0, r = n-1;
        while(l<r)
        {
            if(s[l]!=s[r])
            break;
            char letter = s[l];
            while(l<n && s[l]==letter)
            {
                l++;
            }
            while(r>=0 && s[r]==letter)
            {
                r--;
            }
        }
        return max(r-l+1,0);
    }
};