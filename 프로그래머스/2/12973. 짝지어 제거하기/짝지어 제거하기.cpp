#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = -1;
    vector<char> v;

    for (int i = 0; i <= s.size(); ++i)
    {
        while (v.size() >= 2)
        {
            if (v[v.size() - 1] == v[v.size() - 2])
            {
                v.pop_back();
                v.pop_back();
            }
            else break;
        }

        if (i == s.size()) break;

        v.push_back(s[i]);
    }

    return v.empty() ? 1 : 0;
}