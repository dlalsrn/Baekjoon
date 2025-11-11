// 가장 먼 노드
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
using pii = pair<int, int>;

int solution(int n, vector<vector<int>> edge)
{
    vector<vector<int>> node(n + 1);
    vector<bool> visit(n + 1, false);
    queue<pii> q;
    int maxDis = -1;
    int answer = 0;

    for (int i = 0; i < edge.size(); i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        node[u].push_back(v);
        node[v].push_back(u);
    }

    q.push(make_pair(1, 0));
    visit[1] = true;
    while (!q.empty())
    {
        auto [next, cnt] = q.front();
        q.pop();

        for (int x : node[next])
        {
            if (!visit[x])
            {
                visit[x] = true;
                q.push(make_pair(x, cnt + 1));

                if (cnt + 1 > maxDis)
                {
                    maxDis = cnt + 1;
                    answer = 1;
                }
                else if (cnt + 1 == maxDis)
                {
                    answer++;
                }
            }
        }
    }

    return answer;
}