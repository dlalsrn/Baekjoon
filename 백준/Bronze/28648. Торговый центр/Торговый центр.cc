#include <bits/stdc++.h>
using namespace std;

int N, a, b;
int ans = 1e9;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		ans = min(ans, a + b);
	}

	cout << ans;
}