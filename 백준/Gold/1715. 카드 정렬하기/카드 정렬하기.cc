#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	priority_queue <int, vector<int>, greater<int>> q;
	int N, num;
	long long sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		q.push(num);
	}

	if (N != 1)
	{
		while (true)
		{
			int first = q.top();
			q.pop();
			int second = q.top();
			q.pop();
			sum += (first + second);
			if (q.empty())
				break;
			else
				q.push(first + second);
		}
	}
	cout << sum;
	return 0;
}