// 부대복귀
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;
using pi = pair<int, int>;

vector<vector<int>> node;
vector<int> minPath;
queue<pi> q;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
    vector<int> answer;

    node = vector<vector<int>>(n + 1);
    minPath = vector<int>(n + 1, n);
    q = queue<pi>();

    for (int i = 0; i < roads.size(); ++i)
    {
        int u = roads[i][0];
        int v = roads[i][1];
        node[u].push_back(v);
        node[v].push_back(u);
    }

    q.push(make_pair(destination, 0));
    minPath[destination] = 0;

    while (!q.empty())
    {
        int next = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int x : node[next])
        {
            if (cnt + 1 >= minPath[x])
            {
                continue;
            }

            minPath[x] = cnt + 1;
            q.push(make_pair(x, cnt + 1));
        }
    }

    for (int i = 0; i < sources.size(); i++)
    {
        int path = minPath[sources[i]] != n ? minPath[sources[i]] : -1;
        answer.push_back(path);
    }

    return answer;
}

int main(void)
{
    solution(3, { {1,2}, {2,3} }, { 2,3 }, 1);
}