#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

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
priority_queue<pi, vector<pi>, cmp2> keep;
priority_queue<pi, vector<pi>, cmp1> pq;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		pq.push(make_pair(a, b));
	}

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

	while (!keep.empty())
	{
		pi t = keep.top();
		keep.pop();

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