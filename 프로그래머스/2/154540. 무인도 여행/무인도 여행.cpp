#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void DFS(vector<string>& map, vector<vector<bool>>& visit, int y, int x, int& sum)
{
    visit[y][x] = true;
    sum += map[y][x] - '0';

    for (int k = 0; k < 4; k++)
    {
        int yy = y + dy[k];
        int xx = x + dx[k];

        if (yy < 0 || xx < 0 || yy >= map.size() || xx >= map[0].size() || visit[yy][xx] || map[yy][xx] == 'X')
        {
            continue;
        }

        DFS(map, visit, yy, xx, sum);
    }
}

vector<int> solution(vector<string> maps)
{
    vector<int> answer;
    vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].size(), false));

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (!visit[i][j] && maps[i][j] != 'X')
            {
                int sum = 0;
                DFS(maps, visit, i, j, sum);
                answer.push_back(sum);
            }
        }
    }

    if (answer.empty())
    {
        answer.push_back(-1);
    }
    else
    {
        sort(answer.begin(), answer.end());
    }

    return answer;
}