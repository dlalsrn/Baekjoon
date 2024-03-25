#include <bits/stdc++.h>
using namespace std;

int N, M, x, cnt, ans = 0;
deque <int> dq;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) dq.push_back(i);

	for (int i = 0; i < M; i++)
	{
		cin >> x;
		
		while (dq.front() != x)
		{
			cnt++;
			dq.push_back(dq.front());
			dq.pop_front();
		}

		ans += min(cnt, (int)dq.size() - cnt);

		dq.pop_front();
		cnt = 0;
	}

	cout << ans;

	return 0;
}