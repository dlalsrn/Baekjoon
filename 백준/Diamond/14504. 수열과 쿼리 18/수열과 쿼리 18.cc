#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int N, M, S, ch, a, b, c, cnt;
int v[100001] = {};
vector <vector<int>> bucket;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	S = sqrt(N);
	bucket.resize(N / S + 1);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		bucket[i / S].push_back(v[i]);
	}

	for (int i = 0; i < N / S + 1; i++) sort(bucket[i].begin(), bucket[i].end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> ch >> a >> b;
		a--;
		int s = a / S + 1;

		if (ch == 1)
		{
			b--;
			cin >> c;
			cnt = 0;
			int e = b / S;

			for (int k = a; k <= min(b, s * S - 1); k++) cnt += (v[k] > c ? 1 : 0);
			for (int k = b; k >= max(s * S, e * S); k--) cnt += (v[k] > c ? 1 : 0);
			for (int k = s; k < e; k++) cnt += (bucket[k].end() - upper_bound(bucket[k].begin(), bucket[k].end(), c));

			cout << cnt << '\n';
		}
		else
		{
			s--;
			auto i = lower_bound(bucket[s].begin(), bucket[s].end(), v[a]);
			v[a] = b;
			*i = b;
			sort(bucket[s].begin(), bucket[s].end());
		}
	}

	return 0;
}