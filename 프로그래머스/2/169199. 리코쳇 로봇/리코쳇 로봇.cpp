// 리코쳇 로봇
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
using pii = pair<pair<int, int>, int>; // { { y, x }, cnt }

int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0, 1, 0, -1 };

int solution(vector<string> board)
{
    int answer = -1;
    
    queue<pii> q;
    vector<vector<char>> map;
    vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));

    for (int i = 0; i < board.size(); i++)
    {
        string s = board[i];

        vector<char> t;
        for (int j = 0; j < s.size(); j++)
        {
            char c = s[j];
            if (c == 'R')
            {
                visit[i][j] = true;
                q.push(make_pair(make_pair(i, j), 0));
            }

            t.push_back(c);
        }

        map.push_back(t);
    }

    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (map[y][x] == 'G')
        {
            answer = cnt;
            break;
        }

        for (int k = 0; k < 4; k++)
        {
            int yy = y;
            int xx = x;
            bool isOut = false;

            while (true)
            {
                yy += dy[k];
                xx += dx[k];

                if (yy < 0 || xx < 0 || yy >= board.size() || xx >= board[0].size() || map[yy][xx] == 'D')
                {
                    yy -= dy[k];
                    xx -= dx[k];
                    break;
                }
            }

            if (!isOut && !visit[yy][xx])
            {
                visit[yy][xx] = true;
                q.push(make_pair(make_pair(yy, xx), cnt + 1));
            }
        }
    }

    return answer;
}