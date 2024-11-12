#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

ll N, M, a, b;
ll low, high, mid, ans = 0;
vector <pl> v;

bool ispossible(ll dis)
{
	ll i = 0, cow = v[0].first, cnt = 1;

	while (i < M && cnt <= N) {
		if (cow + dis <= v[i].second) {
			cnt++;
			if (cow + dis >= v[i].first) cow += dis;
			else cow = v[i].first;
		}
		else {
			i++;
		}
	}

	return (cnt >= N ? true : false); // 간격 dis로 N마리 이상의 소가 설 수 있나
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v.emplace_back(a, b);
	}

	sort(v.begin(), v.end());

	low = 0, high = v[M - 1].second / (N - 1);

	while (low <= high) {
		mid = (low + high) / 2;
		if (ispossible(mid)) {
			ans = max(ans, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << ans;

	return 0;
}