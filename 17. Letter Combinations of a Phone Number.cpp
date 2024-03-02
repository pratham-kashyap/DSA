// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
class Solution {
public:
    vector<string> calculate(vector<string> first, vector<string> second)
    {
        vector<string> result;
        int f = first.size();
        int s = second.size();
        for(int i=0;i<f;i++)
        {
            for(int j=0;j<s;j++)
            {
                result.push_back(first[i]+""+second[j]);
            }
        }
        return result;
    }

    vector<string> letterCombinations(string digits) {
        map<char,vector<string>> mp;
        mp['2'] = {"a","b","c"};
        mp['3'] = {"d","e","f"};
        mp['4'] = {"g","h","i"};
        mp['5'] = {"j","k","l"};
        mp['6'] = {"m","n","o"};
        mp['7'] = {"p","q","r","s"};
        mp['8'] = {"t","u","v"};
        mp['9'] = {"w","x","y","z"};
        vector<string>ans;
        int n = digits.length();
        for(int i=0;i<n;i++)
        {
            if(i==0)
            ans = mp[digits[0]];
            else
            ans = calculate(ans,mp[digits[i]]);
        }
        return ans;
    }
};
