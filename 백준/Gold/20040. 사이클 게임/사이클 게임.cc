#include <iostream>
#include <vector>
using namespace std;
vector <int> parent; // 각 정점의 부모를 저장
int N, M, ans = 0, a, b;

void set_parent()
{
	for (int i = 1; i <= N; i++)
		parent[i] = i;
}

int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

bool SameSet(int x, int y)
{
	int px = find(x);
	int py = find(y);
	if (px == py)
		return true;
	else
		return false;
}

void Union(int x, int y)
{
	int px = find(x);
	int py = find(y);
	if (px != py)
		parent[px] = py;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	parent = vector<int>(N + 1);
	set_parent();

	for (int i = 0, cnt = 1; i < M; i++, cnt++)
	{
		cin >> a >> b;
		if (ans)
			continue;
		if (!SameSet(a, b))
			Union(a, b);
		else
			ans = cnt;
	}
	cout << ans ? ans : 0;

	return 0;
}