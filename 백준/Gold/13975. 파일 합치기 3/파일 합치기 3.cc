
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int T, N, num;
	cin >> T;

	for (int j = 0; j < T; j++)
	{
		long long sum = 0;
		priority_queue <long long, vector<long long>, greater<long long>> q;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			q.push(num);
		}

		while (true)
		{
			long long first = q.top();
			q.pop();
			long long second = q.top();
			q.pop();
			sum += (first + second);
			if (q.empty())
				break;
			else
				q.push(first + second);
		}
		cout << sum << '\n';
	}
	return 0;
}