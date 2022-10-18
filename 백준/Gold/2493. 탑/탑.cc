// 탑
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector <int> top;
	stack <pair<int, int>> total;
	int N, h;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> h;
		top.push_back(h);
	}

	for (int i = 0; i < N; i++)
	{
		while (!total.empty() && total.top().first < top[i])
			total.pop();
		if (total.empty())
			cout << 0 << ' ';
		else
			cout << total.top().second << ' ';
		total.push({ top[i], i + 1 });
	}
	return 0;
}