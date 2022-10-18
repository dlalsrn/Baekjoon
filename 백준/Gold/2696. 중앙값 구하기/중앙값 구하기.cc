#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int T, M, num;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		priority_queue <int> max;
		priority_queue <int, vector<int>, greater<int>> min;
		cin >> M;
		cout << M / 2 + 1;
		for (int i = 1; i <= M; i++)
		{
			cin >> num;
			if (i == 1)
				max.push(num);
			else
			{
				if (max.size() == min.size())
				{
					if (min.top() < num)
					{
						int temp = min.top();
						min.pop();
						min.push(num);
						max.push(temp);
					}
					else
						max.push(num);
				}
				else
				{
					if (max.top() > num)
					{
						int temp = max.top();
						max.pop();
						max.push(num);
						min.push(temp);
					}
					else
						min.push(num);
				}
			}
			if (i % 20 == 1)
				cout << '\n';
			if (i % 2 != 0)
				cout << max.top() << ' ';
		}
		cout << '\n';
	}
	return 0;
}