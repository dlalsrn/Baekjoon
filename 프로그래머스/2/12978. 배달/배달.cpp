#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;
    vector<vector<pi>> node(N + 1);
    vector<bool> visit(N + 1, false);
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    for (int i = 0; i < road.size(); i++)
    {
        int u = road[i][0];
        int v = road[i][1];
        int w = road[i][2];

        node[u].push_back(make_pair(v, w));
        node[v].push_back(make_pair(u, w));
    }

    pq.push(make_pair(0, 1));

    while (!pq.empty())
    {
        auto [totalWeight, n] = pq.top();
        pq.pop();

        if (totalWeight > K || visit[n])
        {
            continue;
        }

        visit[n] = true;
        answer++;

        for (auto [x, w] : node[n])
        {
            if (!visit[x])
            {
                pq.push(make_pair(totalWeight + w, x));
            }
        }
    }

    return answer;
}