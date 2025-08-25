#include <bits/stdc++.h>
using namespace std;

string ChangetoBinary(int n)
{
    string t = "";

    while (n)
    {
        t = to_string(n % 2) + t;
        n /= 2;
    }

    return t;
}

vector<int> solution(string s)
{
    vector<int> answer;
    int cnt = 0;
    int zero = 0;

    while (s != "1")
    {
        cnt++;

        string t = "";
        for (char& c : s)
        {
            if (c == '1')
            {
                t += c;
            }
            else
            {
                zero++;
            }
        }
        s = t;

        int len = s.size();

        s = ChangetoBinary(len);
    }

    answer.push_back(cnt);
    answer.push_back(zero);

    return answer;
}