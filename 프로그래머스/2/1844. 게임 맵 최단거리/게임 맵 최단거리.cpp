#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

struct point
{
    point(int x, int y, int cnt)
    {
        this->x = x;
        this->y = y;
        this->cnt = cnt;
    }

    int x;
    int y;
    int cnt;
};

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<bool>> visit(n, vector<bool>(m, false));

    queue<point> q;
    q.push(point(0, 0, 1));
    visit[0][0] = true;

    while (!q.empty())
    {
        point p = q.front();
        q.pop();

        if (p.y == n - 1 && p.x == m - 1)
        {
            return p.cnt;
        }

        for (int k = 0; k < 4; ++k)
        {
            int xx = p.x + dx[k];
            int yy = p.y + dy[k];

            if (xx < 0 || xx >= m || yy < 0 || yy >= n || visit[yy][xx] || maps[yy][xx] == 0) continue;

            visit[yy][xx] = true;
            q.push(point(xx, yy, p.cnt + 1));
        }
    }

    return -1;
}