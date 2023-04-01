#include <iostream>
#include <queue>
using namespace std;

queue <int> q;
int N, K, t;

int main(void)
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		q.push(i);

	cout << "<";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K - 1; j++)
		{
			t = q.front();
			q.pop();
			q.push(t);
		}

		cout << q.front();
		q.pop();

		if (i != N - 1)
			cout << ", ";
	}

	cout << ">";
	return 0;
}