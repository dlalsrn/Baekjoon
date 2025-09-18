// 광물 캐기
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

map<pair<int, string>, int> m;

pair<int, int> dig(vector<string>& minerals, int index, int& curCnt)
{
    int fatigue = 0;
    int cnt = 0;
    int mx = min(static_cast<int>(minerals.size()), curCnt + 5);

    for (cnt = curCnt; cnt < mx; cnt++)
    {
        int val = 0;
        if (index == 0)
        {
            val = 1;
        }
        else if (index == 1)
        {
            val = 1;
            if (minerals[cnt] == "diamond") val = 5;
        }
        else if (index == 2)
        {
            val = 1;
            if (minerals[cnt] == "diamond") val = 25;
            else if (minerals[cnt] == "iron") val = 5;
        }

        //fatigue += m[make_pair(index, minerals[cnt])];
        fatigue += val;
    }

    return make_pair(fatigue, cnt - curCnt);
}

void BackTrack(vector<int>& picks, vector<string>& minerals, int& answer, int fatigue, int cnt, int totalAx)
{
    if (cnt == minerals.size() || totalAx == 0)
    {
        answer = min(answer, fatigue);
        return;
    }

    for (int i = 0; i < picks.size(); i++)
    {
        if (picks[i])
        {
            picks[i]--;
            auto [useFatigue, cntMineral] = dig(minerals, i, cnt);
            BackTrack(picks, minerals, answer, fatigue + useFatigue, cnt + cntMineral, totalAx - 1);
            picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals)
{
    int answer = minerals.size() * 25;
    int totalAx = 0;

    for (int i = 0; i < picks.size(); i++)
    {
        totalAx += picks[i];
        /*m[make_pair(i, "diamond")] = pow(5, max(i, 0));
        m[make_pair(i, "iron")] = pow(5, max(i - 1, 0));
        m[make_pair(i, "stone")] = pow(5, max(i - 2, 0));*/
    }

    BackTrack(picks, minerals, answer, 0, 0, totalAx);

    return answer;
}