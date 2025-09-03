#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (long long n : numbers)
    {
        string s = "";

        while (n)
        {
            s = to_string(n % 2) + s;
            n /= 2;
        }

        int index;
        for (index = s.size() - 1; index >= 0; index--)
        {
            if (s[index] == '0')
            {
                s[index] = '1';
                break;
            }
        }

        if (index == -1)
        {
            index = 0;
            s = '1' + s;
        }
        index++;

        for (; index < s.size(); index++)
        {
            if (s[index] == '1')
            {
                s[index] = '0';
                break;
            }
        }

        long long total = 0;
        long long exp = 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            total += exp * (s[i] - '0');
            exp *= 2;
        }

        answer.push_back(total);
    }

    return answer;
}