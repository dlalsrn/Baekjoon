#include <bits/stdc++.h>
using namespace std;
using ti3 = tuple<int, int, int>; // {횟수, index, num}
using pi = pair<int, int>;

int N, K, P, M, S;
bool TF = false;
vector <int> v;
vector <pi> cnt;
priority_queue <ti3, vector<ti3>, greater<>> pq;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> K >> P >> M;

	cnt = vector<pi>(K, { 0, -1 }); // 횟수, index

	for (int i = 0; i < M; i++)
	{
		cin >> S;
		if (cnt[S - 1].second != -1 && i - cnt[S - 1].second < P) {
			TF = true;
		}
		cnt[S - 1] = make_pair(cnt[S - 1].first + 1, i);
		v.push_back(S);
	}

	if (TF) {
		cout << "impossible";
		return 0;
	}
	else
	{
		for (int i = 0; i < K; i++) {
			pq.push(make_tuple(cnt[i].first, cnt[i].second, i + 1));
		}

		for (int i = M; i < N; i++) {
			auto [a, b, c] = pq.top(); // 횟수, index, num
			pq.pop();

			if (b != -1 && i - b < P) {
				cout << "impossible";
				return 0;
			}
			else {
				v.push_back(c);
				pq.push(make_tuple(a + 1, i, c));
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << v[i] << ' ';
	}

	return 0;
}