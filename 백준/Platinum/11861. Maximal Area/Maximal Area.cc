// 퍼즐 자르기
// 22.07.22
// 구간의 개수 * 구간의 최솟값의 최댓값을 구하는 문제
#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
int main(void)
{
	ll N, n, cnt = 0, max = 0;
	stack <pair<ll, ll>> s;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> n;
		if (s.empty())
			s.push(make_pair(n, 1));
		else
		{
			cnt = 0;
			while (!s.empty() && s.top().first > n)
			{
				cnt += s.top().second;
				if (s.top().first * cnt > max)
					max = s.top().first * cnt;
				s.pop();
			}
			s.push(make_pair(n, cnt + 1));
		}
	}
	cnt = 0;
	while (!s.empty())
	{
		cnt += s.top().second;
		if (s.top().first * cnt > max)
			max = s.top().first * cnt;
		s.pop();
	}
	cout << max << '\n';
	return 0;
}