// 트리의 부모 찾기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	int N, n1, n2;
	cin >> N;
	vector <vector<int>> v(N + 1);
	vector <int> check(N + 1);
	vector <bool> visit(N + 1, false);
	queue <int> q;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	q.push(1);
	visit[1] = true;
	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		for (int i = 0; i < v[n].size(); i++)
		{
			if (!visit[v[n][i]])
			{
				visit[v[n][i]] = true;
				check[v[n][i]] = n;
				q.push(v[n][i]);
			}
		}
	}
	for (int i = 2; i <= N; i++)
		cout << check[i] << '\n';
	return 0;
}