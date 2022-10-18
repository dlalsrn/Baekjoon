//s
#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

int main(void)
{
	ll N, num, cnt = 0;
	bool TF;
	stack <pair<ll, ll>> s;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		TF = false;
		cin >> num;
		if (i == 0)
			s.push({ num, 1 });
		else
		{
			if (s.top().first <= num)
			{
				while(!s.empty() && s.top().first <= num)
				{
					if (s.top().first == num)
					{
						cnt += s.top().second;
						pair <ll, ll> temp = { num, 1 + s.top().second };
						s.pop();
						if (!s.empty())
							cnt++;
						s.push(temp);
						TF = true;
						break;
					}
					else
					{
						cnt += s.top().second;
						s.pop();
					}
				}
				if (!s.empty() && !TF)
					cnt++;
				if (!TF)
					s.push({ num, 1 });
			}
			else if (s.top().first > num)
			{
				s.push({ num, 1 });
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}