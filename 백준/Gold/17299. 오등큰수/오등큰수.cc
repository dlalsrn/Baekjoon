#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack <pair<ll, ll>> total;
	vector <ll> n(1000001, 0);
	vector <ll> v;
	vector <ll> print;
	ll N, num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		n[num]++;
		v.push_back(num);
	}
	for (int i = N - 1; i >= 0; i--)
	{
		if (i == N - 1)
		{
			total.push({ v[i], n[v[i]] });
			print.push_back(-1);
		}
		else
		{
			if (total.top().second > n[v[i]])
			{
				print.push_back(total.top().first);
				total.push({ v[i], n[v[i]] });
			}
			else
			{
				while (!total.empty() && total.top().second <= n[v[i]])
					total.pop();
				if (!total.empty())
					print.push_back(total.top().first);
				else
					print.push_back(-1);
				total.push({ v[i], n[v[i]] });
			}
		}
	}
	for (int i = N-1; i >= 0; i--)
	{
		cout << print[i] << ' ';
	}
	return 0;
}