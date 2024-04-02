#include <bits/stdc++.h>
using namespace std;

int N, x;
queue <int> q;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	while (true)
	{
		cin >> x;
		if (x == -1) break;

		if (x)
		{
			if (q.size() != N) 
				q.push(x);
		}
		else q.pop();
	}

	if (q.empty()) cout << "empty";
	else
	{
		while (!q.empty())
		{
			cout << q.front() << ' ';
			q.pop();
		}
	}

	return 0;
}