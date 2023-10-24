#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int H, W, mx, ans = 0;
vector <ii> h;
vector <int> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> W >> H;
	v = vector<int>(W);
	h = vector<ii>(W, {0, 0});

	for (int i = 0; i < W; i++)
		cin >> v[i];

	int L_mx = 0, R_mx = 0;
	int l = 1, r = W - 2;

	for (int i = 1; i < W; i++)
	{
		L_mx = max(L_mx, v[l - 1]);
		R_mx = max(R_mx, v[r + 1]);
		h[l++].first = L_mx;
		h[r--].second = R_mx;
	}

	for (int i = 0; i < W; i++)
	{
		mx = min(h[i].first, h[i].second);
		
		if (mx && mx > v[i])
			ans += (mx - v[i]);
	}

	cout << ans;
	
	return 0;
}