// https://leetcode.com/problems/generate-parentheses/

#include <bits/stdc++.h>
using namespace std;

void genString ( int n, vector<string>& a, string s, int op, int cl )
    {
        if(op==n && cl==n)
        {
            a.push_back(s);
            return;
        }

        if(op<n)
        {
            s.append("(");
            genString(n, a, s, op+1, cl);
            s.pop_back();
        }

        if(cl<op && cl<n)
        {
            s.append(")");
            genString(n, a, s, op, cl+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> a;
        genString(n,a,"",0,0);

        return a;

    }


    int main()
    {
        vector<string> ans = generateParenthesis(3);

        for (auto i : ans)
        {
            cout<<i<<endl;
        }
        
        return 1;
    }