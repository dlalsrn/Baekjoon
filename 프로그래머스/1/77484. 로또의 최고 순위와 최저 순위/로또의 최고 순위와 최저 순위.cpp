#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    int cnt = 0;
    int zero = 0;
    sort(win_nums.begin(), win_nums.end());

    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            zero++;
            continue;
        }

        for (int j = 0; j < win_nums.size(); j++)
        {
            if (lottos[i] == win_nums[j])
            {
                cnt++;
                break;
            }
        }
    }

    answer.push_back(7 - (cnt + zero) >= 6 ? 6 : 7 - (cnt + zero));
    answer.push_back(7 - cnt >= 6 ? 6 : 7 - cnt);
    return answer;
}