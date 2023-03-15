#include <iostream>
#include <vector>
#include <algorithm>
#define inf 100000000
using namespace std;

typedef long long ll;
vector <bool> sosu;
vector <pair<ll, ll>> fold; // 접을 수 있는 가지 수
vector <ll> width;
vector <ll> height;

ll W, H, A, ori_W, ori_H;
ll mn = inf;

int main(void)
{
	cin >> W >> H >> A;
	ori_W = W;
	ori_H = H;

	if (W * H < A)
		cout << -1;
	else
	{
		if (A == 1)
			fold.push_back(make_pair(1, 1));

		for (int i = 1; i * 2 <= A; i++)
		{
			if (A % i == 0)
				fold.push_back(make_pair(i, A / i));
		}

		while (W != 1)
		{
			W = (W + 1) / 2;
			width.push_back(W);
		}

		while (H != 1)
		{
			H = (H + 1) / 2;
			height.push_back(H);
		}

		sort(width.begin(), width.end());
		sort(height.begin(), height.end());

		/*
		while (1)
		{
			int a, b;
			cin >> a >> b;
			cout << width.end() - lower_bound(width.begin(), width.end(), a + 1) + 1 << ' ';
			cout << height.end() - lower_bound(height.begin(), height.end(), b + 1) + 1 << '\n';
		}
		*/
		for (int i = 0; i < fold.size(); i++)
		{
			if (ori_W >= fold[i].first && ori_H >= fold[i].second)
			{
				ll w = 0, h = 0;
				if (fold[i].first != ori_W)
					w = width.end() - lower_bound(width.begin(), width.end(), fold[i].first + 1) + 1;
				if (fold[i].second != ori_H)
					h = height.end() - lower_bound(height.begin(), height.end(), fold[i].second + 1) + 1;
				//cout << fold[i].first << ' ' << fold[i].second << ' ' << w << ' ' << h << '\n';
				mn = min(mn, w + h);
			}
		}

		for (int i = 0; i < fold.size(); i++)
		{
			if (ori_W >= fold[i].second && ori_H >= fold[i].first)
			{
				ll w = 0, h = 0;
				if (fold[i].second != ori_W)
					w = width.end() - lower_bound(width.begin(), width.end(), fold[i].second + 1) + 1;
				if (fold[i].first != ori_H)
					h = height.end() - lower_bound(height.begin(), height.end(), fold[i].first + 1) + 1;
				//cout << fold[i].first << ' ' << fold[i].second << ' ' << w << ' ' << h << '\n';
				mn = min(mn, w + h);
			}
		}

		cout << (mn == inf ? -1 : mn);
	}
}