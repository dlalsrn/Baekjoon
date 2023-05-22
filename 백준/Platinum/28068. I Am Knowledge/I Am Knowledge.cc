#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using pii = pair<ll, pair<ll, ll>>;

struct cmp1
{
	bool operator()(pi a, pi b)
	{
		if (a.first == b.first)
			return a.second < b.second;
		else
			return a.first > b.first;
	}
};

struct cmp2
{
	bool operator()(pi a, pi b)
	{
		if (a.second == b.second)
			return a.first > b.first;
		else
			return a.second < b.second;
	}
};

ll N, a, b, sum = 0;
vector <ll> v1; // 소모
vector <ll> v2; // 얻음
priority_queue<pi, vector<pi>, cmp2> keep;
priority_queue<pi, vector<pi>, cmp1> pq;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v1.push_back(a);
		v2.push_back(b);
	}

	for (int i = 0; i < N; i++)
		pq.push(make_pair(v1[i], v2[i]));

	while (!pq.empty())
	{
		pi t = pq.top();
		pq.pop();

		if (sum - t.first < 0)
		{
			cout << 0;
			return 0;
		}

		if (t.second - t.first < 0)
			keep.push(t);
		else
			sum += (t.second - t.first);
	}

	//cout << sum << '\n';

	while (!keep.empty())
	{
		pi t = keep.top();
		keep.pop();

		//cout << t.first << ' ' << t.second << '\n';

		if (sum - t.first < 0)
		{
			cout << 0;
			return 0;
		}

		sum += (t.second - t.first);
	}

	cout << 1;

	return 0;
}