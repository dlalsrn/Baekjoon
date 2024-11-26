#include <bits/stdc++.h>
using namespace std;

int N, K, T, x;
vector <int> v;

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> K >> T;

	v = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
		v[i] %= K;
	}

	sort(v.begin(), v.end());
	
	int s = 0;
	for (int t = 0; t < T; t++) {
		cin >> x;
		s = (s + x) % K;
		auto index = lower_bound(v.begin(), v.end(), K - s);
		if (index == v.begin()) index = --v.end();
		else --index;
		cout << (*index + s) % K << ' ';
	}

	return 0;
}