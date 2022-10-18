// 이진 탐색 트리
#include <iostream>
#include <set>
#include <math.h>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, Max;
	long long num, left, right, total = 0;
	set <pair<ll, ll>> s;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (i == 0)
		{
			s.insert({ num, 1 });
		}
		else
		{
			auto it = s.lower_bound(pair<ll, ll>(num, 0));
			if (it != s.begin())
			{
				it--;
				left = (*it).second;
				it++;
			}
			else
				left = 0;
			if (it != s.end())
				right = (*it).second;
			else
				right = 0;
			Max = max(left, right) + 1;
			total += Max - 1;
			s.insert({ num, Max });
		}
		cout << total << '\n';
	}
	return 0;
}