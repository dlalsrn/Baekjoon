#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> v;

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
		for (int i = (v.size() == 0 ? 1 : v.back() + 1); i <= N; i++)
		{
			v.push_back(i);
			DFS();
			v.pop_back();
		}
	}
}

int main(void)
{
	cin >> N >> M;
	DFS();
}