#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int N, x, s, e, cnt = 0;
priority_queue <pi, vector<pi>, greater<pi>> cls, room;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> s >> e;
		cls.push(make_pair(s, e));
	}

	for (int i = 0; i < N; i++)
	{
		if (room.empty()) cnt++; // 맨 처음 강의
		else
		{
			// 수업하고 있는 강의 중 가장 빨리 끝나는 강의의 시간이 다음 수업의 시작 시간보다 이르면 
			// 즉, 수업 시간이 겹치지 않는 다면 강의실을 하나 더 배정할 필요가 없음
			if (cls.top().first >= room.top().first) room.pop();
			else cnt++;
		}
		room.push(make_pair(cls.top().second, cls.top().first));
		cls.pop();
	}

	cout << cnt;

	return 0;
}