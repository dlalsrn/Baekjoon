#include <bits/stdc++.h>
using namespace std;

int N, x;
priority_queue <int, vector<int>, greater<int>> pq;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> x;
			pq.push(x);
		}

		while (pq.size() != N)
			pq.pop();
	}

	cout << pq.top();

	return 0;
}