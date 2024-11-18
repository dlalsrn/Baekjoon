#include <bits/stdc++.h>
using namespace std;

int N, ans = 0, mx;
vector <int> v, cnt;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> N;
	
	cnt = vector<int>(N + 1, 0);

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	if (N < 3) {
		cout << N;
	}
	else {
		mx = 0; // 꽂힌 과일의 개수
		int l = 0, r = 0;

		while (r < N) {
			if (cnt[v[r]] == 0) {
				mx++;
			}
			cnt[v[r]]++;
			r++;

			if (mx > 2) {
				if (--cnt[v[l]] == 0) {
					mx--;
				}
				l++;
			}

			ans = max(ans, r - l);
		}
		cout << ans;
	}

	return 0;
}