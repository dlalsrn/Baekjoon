#include <bits/stdc++.h>
using namespace std;

queue <int> q;
int N, ch, a, mx = 0, ans;

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> ch;

		if (ch == 1)
		{
			cin >> a;
			q.push(a);
			if (mx == q.size())
			{
				if (q.back() < ans)
					ans = q.back();
			}
			else if (mx < q.size())
			{
				mx = q.size();
				ans = q.back();
			}
		}
		else q.pop();
	}

	cout << mx << ' ' << ans;

	return 0;
}