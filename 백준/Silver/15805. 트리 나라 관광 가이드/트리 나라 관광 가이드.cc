#include <iostream>
#include <vector>
using namespace std;

int N, n, pn, cnt = 0;
vector <vector<int>> node;
vector <int> parent;
vector <bool> visit;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	parent = vector<int>(N + 1);
	visit = vector<bool>(N + 1, false);

	pn = -1;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		if (!visit[n])
		{
			parent[n] = pn;
			visit[n] = true;
			cnt++;
		}
		pn = n;
	}

	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++)
		cout << parent[i] << ' ';

	return 0;
}