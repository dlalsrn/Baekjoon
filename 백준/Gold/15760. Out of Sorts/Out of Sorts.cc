#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int N, x, cnt, ans = 0, mx = 1;
vector <pi> v;
vector <pi> t;
vector <int> up;

void Sort()
{
	bool s = false;
	int cnt = 0;
	while (!s)
	{
		s = true;
		cnt++;
		for (int i = 0; i < N - 1; i++)
		{
			if (t[i + 1] < t[i])
			{
				swap(t[i], t[i + 1]);
				s = false;
			}
		}
	}

	cout << cnt << '\n';
}


int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(make_pair(x, i));
		t.push_back(make_pair(x, i));
	}

	//Sort();

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
		ans = max(ans, v[i].second - i);

	cout << ans + 1;

	return 0;
}