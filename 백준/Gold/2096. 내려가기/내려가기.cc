#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a = 0, s = 0, d = 0, z = 0, x = 0, c = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		int ta = min(a, s) + q;
		int ts = min(min(a, s), d) + w;
		int td = min(s, d) + e;
		a = ta, s = ts, d = td;
		int tz = max(z, x) + q;
		int tx = max(max(z, x), c) + w;
		int tc = max(x, c) + e;
		z = tz, x = tx, c = tc;
	}
	cout << max(max(z, x), c) << ' ' << min(min(a, s), d);
}