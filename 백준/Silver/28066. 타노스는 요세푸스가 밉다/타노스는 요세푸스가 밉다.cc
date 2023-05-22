#include <iostream>
#include <queue>
using namespace std;

int N, M;
deque <int> dq;

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		dq.push_back(i);

	while (dq.size() >= M)
	{
		int x = dq.front();
		for (int i = 0; i < M; i++)
			dq.pop_front();
		dq.push_back(x);
	}

	cout << dq.front() + 1;

	return 0;
}