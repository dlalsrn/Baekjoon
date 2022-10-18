// Performance Review
// 2022.07.04
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> segtree;
vector <vector<int>> node;
vector <pair<int, int>> query;
vector <pair<int, pair<int, int>>> value;
vector <ll> print;
int cnt = 0;

void DFS(int n, int pn)
{
	query[n].first = ++cnt;
	for (int i = 0; i < node[n].size(); i++)
		DFS(node[n][i], n);
	query[n].second = cnt;
}

void update(int n, int start, int end, int index, ll change)
{
	if (index < start || index > end)
		return;
	if (start == end)
		segtree[n] = change;
	else
	{
		update(n * 2, start, (start + end) / 2, index, change);
		update(n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		segtree[n] = segtree[n * 2] + segtree[n * 2 + 1];
	}
}

ll sum(int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n];
	return sum(n * 2, start, (start + end) / 2, left, right) + sum(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, parent, rank, time, root;
	cin >> N;
	int h = (int)ceil(log2(N));
	segtree = vector <ll>((1 << (h + 1)), 0);
	node = vector <vector<int>>(N + 1);
	query = vector <pair<int, int>>(N + 1);
	print = vector<ll>(N + 1);
	stack <pair<int, pair<int, int>>> s;

	for (int i = 1; i <= N; i++)
	{
		cin >> parent >> rank >> time;
		value.push_back(make_pair(rank, make_pair(time, i)));
		if (parent == -1)
			root = i;
		else
			node[parent].push_back(i);
	}

	DFS(root, 0); // 오일러 경로 테크닉
	sort(value.begin(), value.end()); // rank가 낮은 순으로 정렬

	for (int i = 0; i < N; i++)
	{
		int n = value[i].second.second;
		print[n] = sum(1, 0, N - 1, query[n].first, query[n].second - 1); // 부하 중 자신보다 낮은 수준의 rank를 가진 부하들의 time을 합
		s.push(value[i]);

		if ((i != N - 1) && (value[i + 1].first != s.top().first)) // 만약 i+1번째 직원의 rank가 나랑 다르면 update, 같으면 push
		{
			while (!s.empty())
			{
				update(1, 0, N - 1, query[s.top().second.second].first - 1, (ll)s.top().second.first);
				s.pop();
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << print[i] << '\n';

	return 0;
}