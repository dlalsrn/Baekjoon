#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, string skip, int index)
{
    string answer = "";
    vector<char> v;

    for (int i = 0; i < 26; i++)
    {
        bool isSkip = false;
        for (int j = 0; j < skip.size(); j++)
        {
            if (skip[j] == i + 'a')
            {
                isSkip = true;
                break;
            }
        }

        if (!isSkip) v.push_back(i + 'a');
    }

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (s[i] == v[j])
            {
                answer += v[(j + index) % v.size()];
            }
        }
    }

    return answer;
}