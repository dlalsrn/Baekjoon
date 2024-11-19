#include <bits/stdc++.h>
using namespace std;

int N, r, c;

void cur(int n, int y, int x, int cnt) {
	if (n == 0) {
		cout << cnt;
		return;
	}
	else {
		int s = (int)pow(2, n - 1);
		int t = s * s;
		if (y + s <= r && x + s <= c)
			cur(n - 1, y + s, x + s, cnt + t * 3);
		else if (y + s <= r)
			cur(n - 1, y + s, x, cnt + t * 2);
		else if (x + s <= c)
			cur(n - 1, y, x + s, cnt + t);
		else
			cur(n - 1, y, x, cnt);
	}
}

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> r >> c;

	cur(N, 0, 0, 0);

	return 0;
}