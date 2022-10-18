#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
	int N, x;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 0)
		{
			if (!q.empty())
			{
				cout << q.top().second << '\n';
				q.pop();
			}
			else
				cout << "0\n";
		}
		else
			q.push({abs(x), x});
	}
	return 0;
}