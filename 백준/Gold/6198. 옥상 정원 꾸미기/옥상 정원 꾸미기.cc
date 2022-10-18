// 옥상 정원 꾸미기
#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack <ll> s;
	ll N, n, cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> n;
		if (i == 0)
			s.push(n);
		else
		{
			if (s.top() <= n)
			{
				while (!s.empty() && s.top() <= n)
					s.pop();
				if (!s.empty())
					cnt += s.size();
				s.push(n);
			}
			else
			{
				cnt += s.size();
				s.push(n);
			}
		}
	}
	cout << cnt;
	return 0;
}