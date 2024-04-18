#include <bits/stdc++.h>
using namespace std;

int N, x;
priority_queue <int> pq;
vector <int> v(4);
vector <int> ans;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		pq.push(x);
	}

	while (pq.size() > 4) pq.pop();

	for (int i = 0; i < min(N, 4); i++)
	{
		v[i] = pq.top();
		pq.pop();
	}

	for (int i = 0; i < min(N, 4); i++)
	{
		for (int j = i + 1; j < min(N, 4); j++)
		{
			ans.push_back(stoi(to_string(v[i]) + to_string(v[j])));
			ans.push_back(stoi(to_string(v[j]) + to_string(v[i])));
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans[2];

	return 0;
}