#include <bits/stdc++.h>
using namespace std;

long long N, w, sum = 0, angry = 0;

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> w;

		if (w) angry++;
		else angry--;

		sum += angry;
	}

	cout << sum;

	return 0;
}