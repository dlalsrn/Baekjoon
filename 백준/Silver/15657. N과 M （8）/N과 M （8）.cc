// N과 M (8)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> v;
vector<int> ary;

void DFS()
{
	if (v.size() == M)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';
		cout << '\n';
		return;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (v.size() != 0 && (v.back() > ary[i]))
				continue;
			v.push_back(ary[i]);
			DFS();
			v.pop_back();
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