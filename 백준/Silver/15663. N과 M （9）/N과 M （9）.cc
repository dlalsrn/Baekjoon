// N과 M (9)
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int N, M;
vector<int> last;
vector<int> v;
vector<int> ary;
set<vector<int>> s;
bool visit[8] = { false };

void DFS()
{
	if (v.size() == M)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';
		cout << '\n';
		s.insert(v);
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (visit[i])
				continue;
			v.push_back(ary[i]);
			visit[i] = true;
			if (s.find(v) == s.end())
				DFS();
			v.pop_back();
			visit[i] = false;
		}
	}
}

int main(void)
{
	int num;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		ary.push_back(num);
	}
	sort(ary.begin(), ary.end());
	DFS();
}