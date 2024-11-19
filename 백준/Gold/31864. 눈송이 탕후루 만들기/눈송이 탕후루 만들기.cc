#include <bits/stdc++.h>
#define MID 1'000'000'000
using namespace std;
using pi = pair<int, int>;

int N, M, ori_x, ori_y, x, y, ans = 0;
map <pi, vector<int>> m;
vector <pi> v;

int gcd(int a, int b) {
	return (a % b == 0 ? b : gcd(b, a % b));
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		ori_x = x;
		ori_y = y;
		if (x != 0 && y != 0) {
			int c = abs(gcd(x, y));
			x /= c;
			y /= c;
		}
		else {
			if (x != 0) {
				if (x > 0) x = 1;
				else x = -1;
			}
			else if (y != 0) {
				if (y > 0) y = 1;
				else y = -1;
			}
		}

		if (!m[make_pair(x, y)].size()) {
			v.emplace_back(x, y);
		}
		if (x == 0) m[make_pair(x, y)].push_back(abs(ori_y));
		else m[make_pair(x, y)].push_back(abs(ori_x));
	}

	for (int i = 0; i < v.size(); i++) {
		sort(m[v[i]].begin(), m[v[i]].end());
	}

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		ori_x = x;
		ori_y = y;
		if (x != 0 && y != 0) {
			int c = abs(gcd(x, y));
			x /= c;
			y /= c;
		}
		else {
			if (x != 0) {
				if (x > 0) x = 1;
				else x = -1;
			}
			else if (y != 0) {
				if (y > 0) y = 1;
				else y = -1;
			}
		}
		
		int cnt; 
		if (x == 0) cnt = upper_bound(m[make_pair(x, y)].begin(), m[make_pair(x, y)].end(), abs(ori_y)) - m[make_pair(x, y)].begin();
		else cnt = upper_bound(m[make_pair(x, y)].begin(), m[make_pair(x, y)].end(), abs(ori_x)) - m[make_pair(x, y)].begin();
		ans = max(ans, cnt);
	}

	cout << ans;

	return 0;
}