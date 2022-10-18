#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ans;
int N, L, h, o, mx = 0, start = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> h >> o;
		if (h > o)
			swap(h, o);
		q.push(make_pair(o, h)); // 끝 지점을 기준으로 오름차순 정렬
	}

	cin >> L;
	while(!q.empty())
	{
		if (q.top().first - q.top().second > L)
		{
			q.pop();
			continue;
		}
		ans.push(make_pair(q.top().second, q.top().first)); // 시작 지점으로 오름차순 정렬
		while (!ans.empty() && q.top().first - L > ans.top().first)
			ans.pop();
		q.pop();
		mx = max(mx, (int)ans.size());
	}

	cout << mx;
	return 0;
}