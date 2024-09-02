#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> v, t;
vector <bool> check;

void back(int n)
{
	if (t.size() == 6)
	{
		for (int i = 0; i < 6; i++) cout << t[i] << ' ';
		cout << '\n';
		return;
	}
	else
	{
		for (int i = n; i < N; i++)
		{
			if (check[i]) continue;
			t.push_back(v[i]);
			check[i] = true;
			back(i + 1);
			check[i] = false;
			t.pop_back();
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	while (true)
	{
		cin >> N;

		if (!N) break;

		v = vector<int>(N);
		check = vector<bool>(N, false);
		t = vector<int>();

		for (int i = 0; i < N; i++) cin >> v[i];

		sort(v.begin(), v.end());

		back(0);
		cout << '\n';
	}

	return 0;
}