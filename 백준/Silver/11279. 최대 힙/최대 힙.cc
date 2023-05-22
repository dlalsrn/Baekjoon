// 최대 힙
// 23.05.22
// 우선순위 큐
#include <iostream>
#include <queue>
using namespace std;

int N, x;
priority_queue <int> pq;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (x)
			pq.push(x);
		else
		{
			if (pq.empty())
				cout << "0\n";
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}