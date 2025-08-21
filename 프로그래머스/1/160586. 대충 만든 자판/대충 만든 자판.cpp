#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;
    vector<int> count(26, -1);

    for (int i = 0; i < keymap.size(); i++)
    {
        for (int j = 0; j < keymap[i].size(); j++)
        {
            if (count[keymap[i][j] - 'A'] == -1)
            {
                count[keymap[i][j] - 'A'] = j + 1;
            }
            else
            {
                count[keymap[i][j] - 'A'] = min(count[keymap[i][j] - 'A'], j + 1);
            }
        }
    }

    for (int i = 0; i < targets.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < targets[i].size(); j++)
        {
            if (count[targets[i][j] - 'A'] == -1) // 만들 수 없는 문자라면
            {
                cnt = -1;
                break;
            }
            else
            {
                cnt += count[targets[i][j] - 'A'];
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}