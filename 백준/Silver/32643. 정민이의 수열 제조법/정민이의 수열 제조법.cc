#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
vector <bool> sosu;
vector <int> sum;

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	sosu = vector<bool>(N + 1, false);
	sum = vector<int>(N + 1, 0);
	sum[1] = true;

	for (int i = 2; i * i <= N; i++) {
		if (sosu[i]) continue;
		for (int j = i * i; j <= N; j += i) sosu[j] = true;
	}

	for (int i = 2; i <= N; i++)
		sum[i] = sum[i - 1] + (!sosu[i] ? 1 : 0);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}

	return 0;
}