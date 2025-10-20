// 빛의 경로 사이클
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<vector<char>> map;
vector<vector<vector<bool>>> visit;
vector<int> answer;

int findCycle(int y, int x, int k, int cnt)
{
    if (cnt != 0)
    {
        if (map[y][x] == 'L')
        {
            k = (k + 3) % 4;
        }
        else if (map[y][x] == 'R')
        {
            k = (k + 5) % 4;;
        }
    }

    if (visit[y][x][k])
    {
        return cnt;
    }

    visit[y][x][k] = true;

    int yy = (y + dy[k] + map.size()) % map.size();
    int xx = (x + dx[k] + map[0].size()) % map[0].size();

    return findCycle(yy, xx, k, cnt + 1);
}

vector<int> solution(vector<string> grid)
{

    map = vector<vector<char>>(grid.size(), vector<char>(grid[0].size()));
    visit = vector<vector<vector<bool>>>(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(4, false)));

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            map[i][j] = grid[i][j];
        }
    }

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (!visit[i][j][k])
                {
                    answer.push_back(findCycle(i, j, k, 0));
                }
			}
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}
