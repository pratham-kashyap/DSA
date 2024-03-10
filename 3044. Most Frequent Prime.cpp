// You are given a m x n 0-indexed 2D matrix mat. From every cell, you can create numbers in the following way:

// There could be at most 8 paths from the cells namely: east, south-east, south, south-west, west, north-west, north, and north-east.
// Select a path from them and append digits in this path to the number being formed by traveling in this direction.
// Note that numbers are generated at every step, for example, if the digits along the path are 1, 9, 1, then there will be three numbers generated along the way: 1, 19, 191.
// Return the most frequent prime number greater than 10 out of all the numbers created by traversing the matrix or -1 if no such prime number exists. 
// If there are multiple prime numbers with the highest frequency, then return the largest among them.

// Note: It is invalid to change the direction during the move.

class Solution {
public:
    bool isPrime(int n)
    {
        for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
        return false;
        return true;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int temp;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // east
                temp = mat[i][j];
                for(int k=j+1;k<m;k++)
                {
                    temp = temp*10+mat[i][k];
                    if(temp>10 && isPrime(temp))
                    mp[temp]++;
                }
                // south-east
                temp = mat[i][j];
                for(int l=i+1,k=j+1;l<n && k<m;k++,l++)
                {
                    temp = temp*10+mat[l][k];
                    if(temp>10 && isPrime(temp))
                    mp[temp]++;
                }
                // south
                temp = mat[i][j];
                for(int l=i+1;l<n;l++)
                {
                    temp = temp*10+mat[l][j];
                    if(temp>10 && isPrime(temp))
                    mp[temp]++;
                }
                // south-west
                temp = mat[i][j];
                for(int l=i+1,k=j-1;l<n && k>=0;k--,l++)
                {
                    temp = temp*10+mat[l][k];
                    if(temp>10 && isPrime(temp))
                    mp[temp]++;
                }
                // west
                temp = mat[i][j];
                for(int k=j-1;k>=0;k--)
                {
                    temp = temp*10+mat[i][k];
                    if(temp>10 && isPrime(temp))
                    mp[temp]++;
                }
                // north-west
                temp = mat[i][j];
                for(int l=i-1,k=j-1;l>=0 && k>=0;k--,l--)
                {
                    temp = temp*10+mat[l][k];
                    if(temp>10 && isPrime(temp))
                    mp[temp]++;
                }
                // north
                temp = mat[i][j];
                for(int l=i-1;l>=0;l--)
                {
                    temp = temp*10+mat[l][j];
                    if(temp>10 && isPrime(temp))
                    mp[temp]++;
                }
                // north-east
                temp = mat[i][j];
                for(int l=i-1,k=j+1;l>=0 && k<m;k++,l--)
                {
                    temp = temp*10+mat[l][k];
                    if(temp>10 && isPrime(temp))
                    mp[temp]++;
                }
            }
        }
        if(mp.size()==0)
        return -1;
        int m1 = 0, m2 = 0;
        for(auto it:mp)
        {
            if(it.second>=m2)
            {
                m1 = it.first;
                m2 = it.second;
            }
        }
        return m1;
    }
};
