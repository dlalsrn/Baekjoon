#include <bits/stdc++.h>
using namespace std;

int N, M, S, ch, a, b, c, cnt;
vector <int> v;
vector <vector<int>> bucket;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	S = sqrt(N);
	v.resize(N);
	bucket.resize(N / S + 1);

	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 0; i < N; i++) bucket[i / S].push_back(v[i]);
	for (int i = 0; i < N / S + 1; i++) sort(bucket[i].begin(), bucket[i].end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> ch >> a >> b;
		a--;

		if (ch == 1)
		{
			b--;
			cin >> c;
			cnt = 0;

			while (a % S != 0 && a <= b) cnt += (v[a++] > c ? 1 : 0);
			while ((b + 1) % S != 0 && a <= b) cnt += (v[b--] > c ? 1 : 0);

			while (a <= b)
			{
				cnt += (bucket[a/S].end() -upper_bound(bucket[a / S].begin(), bucket[a / S].end(), c));
				a += S;
			}
			
			cout << cnt << '\n';
		}
		else
		{
			auto i = lower_bound(bucket[a / S].begin(), bucket[a / S].end(), v[a]);
			v[a] = b;
			*i = b;
			sort(bucket[a / S].begin(), bucket[a / S].end());
		}
	}

	return 0;
}