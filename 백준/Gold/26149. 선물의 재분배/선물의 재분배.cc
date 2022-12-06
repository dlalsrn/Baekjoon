#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

vector <pi> take;
vector <pi> give;
vector <string> ans;
ll N, M, mx = 0, mx_index = 0, cnt = 0;

bool cmp(pi a, pi b)
{
	if (a.first != b.first)
		return a.first > b.first;
	return a.second < b.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;

	take.resize(N);
	give.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> take[i].first;
		take[i].second = i;
	}

	sort(take.begin(), take.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		cin >> give[i].first;
		give[i].second = i;
		if (give[i].first > mx)
		{
			mx = give[i].first;
			mx_index = i;
		}
	}

	if (take != give)
	{
		for (int i = 0; i < N; i++)
		{
			if (take[i].second == mx_index || !take[i].first)
				continue;
			cnt++;
			ans.push_back("+ " + to_string(mx_index + 1) + " " + to_string(take[i].first));
		}

		for (int i = 0; i < N; i++)
		{
			if (i == mx_index || !give[i].first)
				continue;
			cnt++;
			ans.push_back("+ " + to_string(i + 1) + " " + to_string(give[i].first));
		}

		cout << cnt << '\n';
		for (int i = 0; i < cnt; i++)
			cout << ans[i] << "\n";
	}
	else
		cout << 0;

	return 0;
}