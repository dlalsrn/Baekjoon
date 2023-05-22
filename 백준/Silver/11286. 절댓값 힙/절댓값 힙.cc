#include <iostream>
#include <queue>
using namespace std;

priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int N, x;

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x)
			q.push(make_pair(abs(x), x));
		else
		{
			if (q.empty())
				cout << "0\n";
			else
			{
				cout << q.top().second << '\n';
				q.pop();
			}
		}
	}

	return 0;
}