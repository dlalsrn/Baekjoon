#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int mx = 0;

void BackTrack(vector<vector<int>>& dungeons, vector<bool>& visit, int remain, int cnt)
{
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (visit[i]) continue;

        int limit = dungeons[i][0];
        int use = dungeons[i][1];

        if (remain >= limit)
        {
            visit[i] = true;
            BackTrack(dungeons, visit, remain - use, cnt + 1);
            visit[i] = false;
        }
    }

    mx = max(mx, cnt);
}

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;
    vector<bool> visit = vector<bool>(dungeons.size(), false);

    BackTrack(dungeons, visit, k, 0);

    return answer = mx;
}