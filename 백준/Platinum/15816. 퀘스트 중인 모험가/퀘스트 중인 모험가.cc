#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector <int> X;
vector <int> segtree;
vector <int> value;
vector <pair<int, pair<int, int>>> query;
int N, M, ch, l, r;

void update(int n, int start, int end, int index)
{
	if (start == end)
		segtree[n] = 1;
	else
	{
		if (index <= (start + end) / 2)
			update(n * 2, start, (start + end) / 2, index);
		else
			update(n * 2 + 1, (start + end) / 2 + 1, end, index);
		segtree[n] = segtree[n * 2] + segtree[n * 2 + 1];
	}
}

int get_sum(int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n];
	return get_sum(n * 2, start, (start + end) / 2, left, right) + get_sum(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	
	value = vector<int>(N);

	for (int i = 0; i < N; i++)
	{
		cin >> value[i];
		X.push_back(value[i]);
	}
	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> ch >> l;
		if (ch == 1)
		{
			query.push_back(make_pair(ch, make_pair(l, 0)));
			X.push_back(l);
		}
		else
		{
			cin >> r;
			query.push_back(make_pair(ch, make_pair(l, r)));
			X.push_back(l);
			X.push_back(r);
		}
	}

	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());

	int h = (int)ceil(log2(X.size()));
	segtree = vector<int>((1 << (h + 1)), 0);

	for (int i = 0; i < N; i++)
		update(1, 0, X.size() - 1, lower_bound(X.begin(), X.end(), value[i]) - X.begin());

	for (int i = 0; i < M; i++)
	{
		if (query[i].first == 1)
			update(1, 0, X.size() - 1, lower_bound(X.begin(), X.end(), query[i].second.first) - X.begin());
		else
			cout << (query[i].second.second - query[i].second.first + 1) - get_sum(1, 0, X.size() - 1, lower_bound(X.begin(), X.end(), query[i].second.first) - X.begin(), lower_bound(X.begin(), X.end(), query[i].second.second) - X.begin()) << '\n';
	}
	return 0;
}