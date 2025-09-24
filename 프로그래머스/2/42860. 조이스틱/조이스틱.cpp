#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name)
{
    int answer = 0;
    int mnMove = 0;
    vector<int> v;

    for (int i = 0; i < name.size(); i++)
    {
        char c = name[i];
        answer += min(c - 'A', 'Z' - c + 1);

        if (c != 'A')
        {
            v.push_back(i);
        }
    }

    if (v.size())
    {
        mnMove = min(v.back(), (int)name.size() - v[0]);
        for (int i = 0; i < v.size() - 1; i++)
        {
            mnMove = min({ mnMove, v[i] * 2 + (int)name.size() - v[i + 1], ((int)name.size() - v[i + 1]) * 2 + v[i]});
        }
    }

    return answer + mnMove;
}