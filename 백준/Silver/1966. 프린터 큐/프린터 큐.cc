#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
	queue <pair<int, int>> q;
	priority_queue <int> rank;
	int T, N, M, num, cnt;
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		queue <pair<int, int>> q;
		priority_queue <int> rank;
		cnt = 0;
		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			rank.push(num);
			q.push({ j, num });
		}
		
		while (true)
		{
			if (q.front().second == rank.top())
			{
				rank.pop();
				cnt++;
				if (q.front().first == M)
				{
					cout << cnt << endl;
					break;
				}
				q.pop();
			}
			else
			{
				pair<int, int> a = q.front();
				q.pop();
				q.push(a);
			}
		}	
	}
	return 0;
}