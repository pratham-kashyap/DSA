// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

class Solution {
public:
    vector<string> calculate(vector<string> ans,int x)
    {
        int n = ans.size();
        vector<string> result;
        string temp;
        char letter;
        for(int i=0;i<n;i++)
        {       
            for(int j = ((ans[i][x-1])<65?ans[i][x-1]-47:ans[i][x-1]-54);j<=2*x+1;j++)
            {
                if(j<10)
                letter = j+48;
                if(j==10) letter = 'A';
                else if(j==11) letter = 'B';
                else if(j==12) letter = 'C';
                else if(j==13) letter = 'D';
                else if(j==14) letter = 'E';
                else if(j==15) letter = 'F';
                result.push_back(ans[i]+letter);
            }
        }
        return result;
    }
    string convert(string num,int n)
    {
        string str(2*n,')');
        int a;
        for(int i=0;i<n;i++)
        {
            if(num[i]<'A')
            a = num[i]-49;
            else
            a = num[i]-56;
            cout<<a<<endl;
            str[a] = '(';
        }
        return str;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            ans.push_back("1");
            else
            {
                ans = calculate(ans,i);
            }
        }
        int m = ans.size();
        for(int i=0;i<m;i++)
        {
            ans[i] = convert(ans[i],n);
        }
        return ans;
    }
};
