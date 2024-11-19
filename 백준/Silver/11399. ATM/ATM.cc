#include <bits/stdc++.h>
using namespace std;

int N, x, sum = 0, wait = 0;
vector <pair<int, int>> v;

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		v.emplace_back(x, i);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		sum += wait + v[i].first;
		wait += v[i].first;
	}

	cout << sum;

	return 0;
}