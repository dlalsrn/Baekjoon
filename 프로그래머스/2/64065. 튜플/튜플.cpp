// 튜플
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;

    vector<vector<int>> totalV;
    vector<int> temp;
    string str = "";
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '{')
        {
            temp = vector<int>();
        }
        else if (s[i] == '}')
        {
            temp.emplace_back(stoi(str));
            totalV.emplace_back(temp);
        }
        else if (s[i] == ',')
        {
            if (!str.empty()) temp.emplace_back(stoi(str));
            str = "";
        }
        else
        {
            str.push_back(s[i]);
        }
    }

    sort(totalV.begin(), totalV.end(), [](vector<int>& a, vector<int>& b) {
        return a.size() < b.size();
    });

    vector<bool> exist(100001, false);

    for (vector<int>& v : totalV)
    {
        for (int& x : v)
        {
            if (!exist[x])
            {
                exist[x] = true;
                answer.emplace_back(x);
            }
        }
    }

    return answer;
}