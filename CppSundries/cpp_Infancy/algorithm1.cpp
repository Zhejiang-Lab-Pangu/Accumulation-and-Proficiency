//
// Created by Administrator on 2022/11/13.
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>


// 大数相乘


string addStrings(string & a, string & b);

string multiply(string& s1, string s2)
{
    int m = s1.size(), n = s2.size();
    string rslt;

    for(int i = n-1; i>=0; --i)
    {
        int add = 0;
        int y = s2.at(i) - '0';
        string rs;

        for(int k=n-1; k>i; --k)
        {
            rs.push_back(0);
        }


        for(int j = m-1; j>=0; --j)
        {
            int x = s1.at(j) - '0';
            int tmp = x * y + add;
            rs.push_back(tmp % 10);
            add /= 10;
        }

        if(add !=0)
        {
            rs.push_back(add);
        }

        for(char & it: rs)
        {
            it += '0';
        }

        reverse(rs.begin(), rs.end());

        cout << rs << endl;
        rslt = addStrings(rslt, rs);
    }
    return rslt;
}


// 大数相加
string addStrings(string & a, string & b)
{
    int l = a.size()-1, n = b.size()-1, add=0;
    string ans;
    while(l >=0 || n >= 0 || add !=0)
    {
        int x = (l >= 0 ? a.at(l) - '0' : 0);
        int y = (n >=0 ? b.at(n) - '0' : 0);
        int tmp = x + y + add;

        ans.push_back(tmp % 10);
        add = tmp / 10;
        n --;
        l--;
    }

    reverse(ans.begin(), ans.end());

    for(auto & ch : ans)
    {
        ch += '0';
    }
    return ans;
}



int main()
{
    string a = "90987463334";
    string b = "456";
    string s = multiply(a, b);
    cout << s << endl;
    return 0;
}