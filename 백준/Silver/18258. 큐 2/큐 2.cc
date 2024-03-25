#include <bits/stdc++.h>
using namespace std;

int N, a;
string ch;
queue <int> q;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> ch;

		if (ch == "push")
		{
			cin >> a;
			q.push(a);
		}
		else if (ch == "pop")
		{
			if (q.empty()) cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (ch == "size") cout << q.size() << '\n';
		else if (ch == "empty") cout << q.empty() << '\n';
		else if (ch == "front")
		{
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if (ch == "back")
		{
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}

	return 0;
}