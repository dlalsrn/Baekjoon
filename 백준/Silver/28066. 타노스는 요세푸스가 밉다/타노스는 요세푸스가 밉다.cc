#include <iostream>
#include <queue>
using namespace std;

int N, M;
queue <int> q;

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		q.push(i);

	while (q.size() >= M)
	{
		q.push(q.front());
		for (int i = 0; i < M; i++)
			q.pop();
	}

	cout << q.front() + 1;

	return 0;
}