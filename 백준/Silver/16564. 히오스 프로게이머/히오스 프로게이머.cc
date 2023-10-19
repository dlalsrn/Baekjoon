#include <iostream>
#include <queue>
using namespace std;
using pi = pair<int, int>;

priority_queue <pi, vector<pi>, greater<pi>> pq;
int N, K, x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		pq.push(make_pair(x, 1));
	}

	while (true)
	{
		int cnt = pq.top().second;
		int now = pq.top().first;

		if (cnt > K)
			break;

		pq.pop();

		while (!pq.empty() && pq.top().first == now)
		{
			cnt += pq.top().second;
			pq.pop();
		}

		if (pq.empty())
		{
			pq.push(make_pair(now + K / cnt, cnt));
			K -= K / cnt * cnt;
		}
		else
		{
			int next = pq.top().first;
			int diff = ((next - now) * cnt <= K ? next - now : K / cnt);
			pq.push(make_pair(now + diff, cnt));
			K -= diff * cnt;
		}
	}

	cout << pq.top().first;

	return 0;
}