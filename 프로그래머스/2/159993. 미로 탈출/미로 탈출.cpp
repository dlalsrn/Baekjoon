#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
using pi = pair<int, int>;
using ppi = pair<pi, int>; // { { y, x }, cnt }

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(vector<vector<char>>& map, vector<vector<bool>>& visit)
{
    queue<ppi> q;
    int startToLever = 0;
    int leverToExit = 0;

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            if (map[i][j] == 'S')
            {
                q.push(make_pair(make_pair(i, j), 0));
                visit[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (map[y][x] == 'L')
        {
            startToLever = cnt;
            while (!q.empty())
            {
                q.pop();
            }
            q.push(make_pair(make_pair(y, x), 0));
            break;
        }

        for (int k = 0; k < 4; k++)
        {
            int yy = y + dy[k];
            int xx = x + dx[k];

            if (yy < 0 || xx < 0 || yy >= map.size() || xx >= map[0].size() || map[yy][xx] == 'X' || visit[yy][xx])
            {
                continue;
            }

            visit[yy][xx] = true;
            q.push(make_pair(make_pair(yy, xx), cnt + 1));
        }
    }

    for (auto& row : visit)
    {
        row.assign(row.size(), false);
    }

    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (map[y][x] == 'E')
        {
            leverToExit = cnt;
            break;
        }

        for (int k = 0; k < 4; k++)
        {
            int yy = y + dy[k];
            int xx = x + dx[k];

            if (yy < 0 || xx < 0 || yy >= map.size() || xx >= map[0].size() || map[yy][xx] == 'X' || visit[yy][xx])
            {
                continue;
            }

            visit[yy][xx] = true;
            q.push(make_pair(make_pair(yy, xx), cnt + 1));
        }
    }

    return (startToLever != 0 && leverToExit != 0) ? startToLever + leverToExit : -1;
}

int solution(vector<string> maps)
{
    int answer = -1;
    vector<vector<char>> map;
    vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].size(), false));

    for (string s : maps)
    {
        vector<char> v;
        for (char c : s)
        {
            v.push_back(c);
        }
        map.push_back(v);
    }

    answer = BFS(map, visit);

    return answer;
}