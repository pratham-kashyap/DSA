// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

class Solution {
public:
    long long printNcR(int n, int r)
    {
        long long p = 1, k = 1;
        if (n - r < r)
            r = n - r;
    
        if (r != 0) {
            while (r) {
                p *= n;
                k *= r;
                long long m = __gcd(p, k);
                p /= m;
                k /= m;
                n--;
                r--;
            }
        }  
        else
            p = 1;
        return p;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i=0;i<=rowIndex;i++)
        ans.push_back(printNcR(rowIndex,i));
        return ans;
    }
};
