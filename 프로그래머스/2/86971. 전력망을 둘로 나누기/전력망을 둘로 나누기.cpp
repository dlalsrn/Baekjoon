#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int DFS(vector<vector<int>>& node, vector<bool>& visit, int n)
{
    int cnt = 1;

    for (int x : node[n])
    {
        if (!visit[x])
        {
            visit[x] = true;
            cnt += DFS(node, visit, x);
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = n;

    vector<vector<int>> node(n + 1);
    vector<bool> visit(n + 1);

    for (int i = 0; i < wires.size(); i++)
    {
        int u = wires[i][0];
        int v = wires[i][1];
        node[u].push_back(v);
        node[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int x : node[i])
        {
            visit = vector<bool>(n + 1, false);
            visit[i] = true;
            visit[x] = true;

            int cnt1 = DFS(node, visit, i);
            int cnt2 = DFS(node, visit, x);

            answer = min(answer, abs(cnt1 - cnt2));
        }
    }

    return answer;
}