#include <string>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
using namespace std;

int find(int x, vector<int>& parent)
{
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x], parent);
}

void merge(int a, int b, vector<int>& parent)
{
    a = find(a, parent);
    b = find(b, parent);

    parent[b] = a;
}

bool isSame(int a, int b, vector<int>& parent)
{
    a = find(a, parent);
    b = find(b, parent);

    return a == b;
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);

    auto cmp = [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    };

    sort(costs.begin(), costs.end(), cmp);

    for (int i = 0; i < costs.size(); i++)
    {
        int u = costs[i][0];
        int v = costs[i][1];
        int cost = costs[i][2];

        if (!isSame(u, v, parent))
        {
            answer += cost;
            merge(u, v, parent);
        }
    }

    return answer;
}