#include <bits/stdc++.h>
using namespace std;

int N;
queue <int> q;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++) q.push(i);

	while (true)
	{
		cout << q.front() << ' ';
		q.pop();
		if (q.empty()) break;
		q.push(q.front());
		q.pop();
	}

	return 0;
}