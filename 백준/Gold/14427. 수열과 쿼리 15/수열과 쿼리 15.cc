#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using pi = pair<int, int>;
priority_queue <pi, vector<pi>, greater<pi>> pq;
vector <int> v;

int N, M, x, ch, a, b;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
		pq.push(make_pair(x, i));
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> ch;

		if (ch == 1)
		{
			cin >> a >> b;
			v[a - 1] = b;
			pq.push(make_pair(b, a - 1));
		}
		else
		{
			int n = pq.top().first;
			int index = pq.top().second;
			while (v[index] != n)
			{
				pq.pop();
				n = pq.top().first;
				index = pq.top().second;
			}
			cout << index + 1 << '\n';
		}
	}

	return 0;
}