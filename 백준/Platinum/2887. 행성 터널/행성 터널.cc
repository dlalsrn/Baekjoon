#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define be(v) v.begin(), v.end()
using namespace std;
typedef pair<int, int> pi;
vector <pi> X;
vector <pi> Y;
vector <pi> Z;
vector <vector<pi>> node;
vector <bool> visit;
priority_queue <pi, vector<pi>, greater<pi>> q; // 비용, 연결된 노드
int N, x, y, z, cost = 0;

void find_spanning(int n)
{
	visit[n] = true;
	for (int i = 0; i < node[n].size(); i++)
		if (!visit[node[n][i].first])
			q.push(make_pair(node[n][i].second, node[n][i].first));
	while (!q.empty() && visit[q.top().second])
		q.pop();
	if (q.empty())
		return;
	int next_node = q.top().second;
	cost += q.top().first;
	q.pop();
	find_spanning(next_node);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	node = vector<vector<pi>>(N + 1);
	visit = vector<bool>(N + 1, false);

	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y >> z;
		X.push_back(make_pair(x, i));
		Y.push_back(make_pair(y, i));
		Z.push_back(make_pair(z, i));
	}
	sort(be(X));
	sort(be(Y));
	sort(be(Z));

	for (int i = 0; i < N - 1; i++)
	{
		node[X[i].second].push_back(make_pair(X[i + 1].second, abs(X[i].first - X[i + 1].first)));
		node[X[i + 1].second].push_back(make_pair(X[i].second, abs(X[i].first - X[i + 1].first)));
		node[Y[i].second].push_back(make_pair(Y[i + 1].second, abs(Y[i].first - Y[i + 1].first)));
		node[Y[i + 1].second].push_back(make_pair(Y[i].second, abs(Y[i].first - Y[i + 1].first)));
		node[Z[i].second].push_back(make_pair(Z[i + 1].second, abs(Z[i].first - Z[i + 1].first)));
		node[Z[i + 1].second].push_back(make_pair(Z[i].second, abs(Z[i].first - Z[i + 1].first)));
	}

	find_spanning(1);

	cout << cost;

	return 0;
}