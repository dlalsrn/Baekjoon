#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, x;
bool TF;
vector <int> v;
vector <int> t;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> N;
	cout << "Gnomes:\n";

	for (int i = 0; i < N; i++)
	{
		v = vector<int>();
		TF = true;

		for (int j = 0; j < 3; j++)
		{
			cin >> x;
			v.push_back(x);
		}
		t = v;

		sort(t.begin(), t.end());

		for (int j = 0; j < 3; j++)
			if (t[j] != v[j])
				TF = false;

		if (TF)
		{
			cout << "Ordered\n";
			continue;
		}

		TF = true;
		sort(t.begin(), t.end(), greater<>());

		for (int j = 0; j < 3; j++)
			if (t[j] != v[j])
				TF = false;

		cout << (TF ? "Ordered\n" : "Unordered\n");
	}

	return 0;
}