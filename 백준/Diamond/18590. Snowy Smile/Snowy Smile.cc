// 금광
// 22.09.01
// 네모난 구역을 만들었을 때 그 안에 담긴 금광들의 합의 최댓값 출력하는 문제
// 좌표의 값이 크므로 좌표 압축을 해줘야함
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<ll, ll>> pii;
typedef struct
{
	ll L_MAX;
	ll R_MAX;
	ll T_MAX;
	ll ALL;
}NODE;

vector <pii> gold;
vector <ll> X;
vector <ll> Y;
vector <NODE> segtree;
ll T, N, x, y, c, mx;

NODE upt(NODE LEFT, NODE RIGHT)
{
	NODE t;
	t.L_MAX = max(LEFT.L_MAX, LEFT.ALL + RIGHT.L_MAX);
	t.R_MAX = max(RIGHT.R_MAX, RIGHT.ALL + LEFT.R_MAX);
	t.T_MAX = max(LEFT.T_MAX, max(RIGHT.T_MAX, LEFT.R_MAX + RIGHT.L_MAX));
	t.ALL = LEFT.ALL + RIGHT.ALL;
	return t;
}

void update(ll n, ll start, ll end, ll index, ll change)
{
	if (start == end)
	{
		segtree[n].L_MAX += change;
		segtree[n].R_MAX += change;
		segtree[n].T_MAX += change;
		segtree[n].ALL += change;
	}
	else
	{
		if (index <= (start + end) / 2)
			update(n * 2, start, (start + end) / 2, index, change);
		else
			update(n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;

		gold = vector<pii>();
		X = vector<ll>();
		Y = vector<ll>();
		mx = 0;

		for (ll i = 0; i < N; i++)
		{
			cin >> x >> y >> c;
			gold.push_back(make_pair(y, make_pair(x, c)));
			X.push_back(x);
			Y.push_back(y);
		}

		sort(gold.begin(), gold.end()); // y좌표를 오름차순으로 정렬
		sort(X.begin(), X.end()); // x좌표 오름차순으로 정렬
		sort(Y.begin(), Y.end()); // y좌표 오름차순으로 정렬
		X.erase(unique(X.begin(), X.end()), X.end()); // X좌표 압축
		Y.erase(unique(Y.begin(), Y.end()), Y.end()); // Y좌표 압축

		ll h = (ll)ceil(log2(X.size()));

		for (ll y = 0; y < Y.size(); y++)
		{
			segtree = vector<NODE>((1 << (h + 1)), { 0, 0, 0, 0 }); // 초기화
			for (ll i = 0; i < N; i++)
			{
				if (gold[i].first < Y[y]) // 이전 y좌표보다 금광의 y좌표가 작으면 continue
					continue;
				update(1, 0, X.size() - 1, lower_bound(X.begin(), X.end(), gold[i].second.first) - X.begin(), gold[i].second.second);
				if (i < N - 1 && gold[i].first == gold[i + 1].first) // y좌표가 같으면 계속 update
					continue;
				mx = max(mx, segtree[1].T_MAX);
			}
		}

		cout << mx << '\n';
	}

	return 0;
}