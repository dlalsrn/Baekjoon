#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";
    unordered_map<char, int> m;
    vector<string> v = { "RT", "CF", "JM", "AN" };

    for (int i = 0; i < choices.size(); i++)
    {
        int val = choices[i] - 4;

        if (val > 0) m[survey[i][1]] += val;
        else if (val < 0) m[survey[i][0]] += -val;
    }

    for (int i = 0; i < v.size(); i++)
    {
        char t;
        if (m[v[i][0]] > m[v[i][1]]) t = v[i][0];
        else if (m[v[i][0]] < m[v[i][1]]) t = v[i][1];
        else t = min(v[i][0], v[i][1]);
        answer += t;
    }

    return answer;
}