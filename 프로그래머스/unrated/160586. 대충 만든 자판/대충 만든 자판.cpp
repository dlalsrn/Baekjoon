#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    int alpha[26] = { 0 };

    for (int i = 0; i < keymap.size(); i++)
        for (int j = 0; j < keymap[i].size(); j++)
            if (alpha[keymap[i][j]-65] == 0 || alpha[keymap[i][j] - 65] > j)
                alpha[keymap[i][j] - 65] = j + 1;

    for (int i = 0; i < targets.size(); i++)
    {
        int ans = 0;
        for (int j = 0; j < targets[i].size(); j++)
        {
            if (alpha[targets[i][j] - 65] == 0)
            {
                ans = -1;
                break;
            }
            ans += alpha[targets[i][j] - 65];
        }
        answer.push_back(ans);
    }

    return answer;
}