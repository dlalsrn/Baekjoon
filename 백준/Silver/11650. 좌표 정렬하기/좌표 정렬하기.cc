#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int N, x, y;
	priority_queue <pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		q.push({ x, y });
	}
	for (int i = 0; i < N; i++)
	{
		cout << q.top().first << ' ' << q.top().second << '\n';
		q.pop();
	}
	return 0;
}	