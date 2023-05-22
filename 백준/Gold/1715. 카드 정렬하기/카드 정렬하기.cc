#include <iostream>
#include <queue>
using namespace std;

int N, x;
long long sum = 0;
priority_queue <int, vector<int>, greater<int>> q;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		q.push(x);
	}

	while (q.size() != 1)
	{
		int first = q.top();
		q.pop();
		int second = q.top();
		q.pop();

		sum += (first + second);

		q.push(first + second);
	}

	cout << sum;

	return 0;
}