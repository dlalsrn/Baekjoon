#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi2 = pair<ll, ll>;
using pi3 = pair<ll, pi2>;

ll N, M, currenttime = 0, deadline, worktime, addedtime;
ll INF = 1'000'000'000'000'000'000;
priority_queue <pi2, vector<pi2>, greater<pi2>> work; // 처음 주어지는 작업
priority_queue <pi3, vector<pi3>, greater<pi3>> add_work; // 추가로 주어지는 작업

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> worktime >> deadline;
		work.push({ deadline, worktime });
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> addedtime >> worktime >> deadline;
		add_work.push({addedtime, {deadline, worktime}});
	}

	while (!(work.empty() && add_work.empty())) // 둘 다 비어있으면
	{
		pi2 ori_work = (work.empty() ? make_pair(INF, INF) : work.top()); // {마감시간, 작업시간}
		pi3 added_work = (add_work.empty() ? make_pair(INF, make_pair(INF, INF)) : add_work.top()); // {추가되는 시간, {마감시간, 작업시간}}
		
		if (!work.empty()) work.pop();

		if (currenttime + ori_work.second > added_work.first) // 기존 작업 도중에 새로운 작업이 추가되면
		{
			if (!add_work.empty()) add_work.pop();
			work.push(added_work.second);
			ll diff = added_work.first - currenttime;
			currenttime = added_work.first;
			ori_work.second -= diff;
			if (ori_work.first != INF) work.push(ori_work);
		}
		else
		{
			if (currenttime + ori_work.second > ori_work.first)
			{
				cout << "NO";
				return 0;
			}

			currenttime += ori_work.second;
		}
	}

	cout << "YES" << '\n' << currenttime << '\n';

	return 0;
}