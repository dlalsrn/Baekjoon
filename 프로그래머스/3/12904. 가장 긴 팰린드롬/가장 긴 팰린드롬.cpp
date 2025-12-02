#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int l = i;
        int r = i;
        while (l >= 0 && r < s.size())
        {
            if (s[l] == s[r])
            {
                answer = max(answer, r - l + 1);
                l--;
                r++;
            }
            else
            {
                break;
            }
        }

        l = i;
        r = i + 1;

        while (l >= 0 && r < s.size())
        {
            if (s[l] == s[r])
            {
                answer = max(answer, r - l + 1);
                l--;
                r++;
            }
            else
            {
                break;
            }
        }
    }

    return answer;
}