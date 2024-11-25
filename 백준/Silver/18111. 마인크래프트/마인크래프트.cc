#include <bits/stdc++.h>
using namespace std;

int N, M, B, x, ans = 1e9, H;
vector <int> h(257, 0);

int main(void) {
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> N >> M >> B;

	for (int i = 0; i < N * M; i++) {
		cin >> x;
		h[x]++;
	}

	for (int i = 0; i < 257; i++) {
		int a = 0, b = 0; // 쌓을 블럭, 파낸 블럭
		
		for (int j = 0; j < i; j++) {
			a += h[j] * (i - j);
		}

		for (int j = 256; j > i; j--) {
			b += h[j] * (j - i);
		}

		if (b + B >= a) {
			if (b * 2 + a <= ans) {
				ans = b * 2 + a;
				H = i;
			}
		}
	}

	cout << ans << ' ' << H;

	return 0;
}