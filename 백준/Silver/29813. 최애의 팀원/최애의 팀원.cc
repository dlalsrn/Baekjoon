#include <bits/stdc++.h>
using namespace std;

int N, b;
string a;
queue <pair<string, int>> q;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		q.push(make_pair(a, b));
	}

	while (q.size() != 1)
	{
		a = q.front().first;
		b = q.front().second;
		q.pop();

		for (int i = 0; i < b - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		q.pop();
	}

	cout << q.front().first;

	return 0;
}