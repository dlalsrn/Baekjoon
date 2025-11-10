// 네트워크
#include <string>
#include <vector>
using namespace std;

void DFS(int n, vector<vector<int>>& node, vector<bool>& visit)
{
    for (int x : node[n])
    {
        if (!visit[x])
        {
            visit[x] = true;
            DFS(x, node, visit);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    vector<vector<int>> node(n);
    vector<bool> visit(n, false);

    for (int i = 0; i < computers.size(); i++)
    {
        for (int j = 0; j < computers[i].size(); j++)
        {
            if (i == j) continue;

            if (computers[i][j] == 1)
            {
                node[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            visit[i] = true;
            DFS(i, node, visit);
            answer++;
        }
    }

    return answer;
}