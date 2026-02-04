#include <string>
#include <vector>
#include <iostream>
using namespace std;

string Round(int n, string str)
{
    for (int i = str.size() - 1; i >= 0; --i)
    {
        char c = str[i];
        if (c == '9' + 1)
        {
            str[i] = 'A';
            c = 'A';
        }

        int num;
        if ('0' <= c && c <= '9')
        {
            num = c - '0';
        }
        else
        {
            num = c - 'A' + 10;
        }

        if (num < n)
        {
            return str;
        }
        else
        {
            str[i] = '0';

            if (i == 0)
            {
                return '1' + str;
            }
            else
            {
                ++str[i - 1];
            }
        }
    }
}

string solution(int n, int t, int m, int p)
{
    string answer = "";

    string total = "0";
    string temp = "0";

    for (int i = 1; i < t * m; ++i)
    {
        ++temp.back();
        temp = Round(n, temp);
        total.append(temp);
    }

    for (int i = p - 1; t--; i += m)
    {
        answer.push_back(total[i]);
    }

    return answer;
}