#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	priority_queue <int> max;
	priority_queue <int, vector <int>, greater<int>> min;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (i == 0)
			max.push(num);
		else
		{
			if (max.size() - 1 == min.size())
			{
				if (num < max.top())
				{
					int temp = max.top();
					max.pop();
					max.push(num);
					min.push(temp);
				}
				else
					min.push(num);
			}
			else
			{
				if (num > min.top())
				{
					int temp = min.top();
					min.pop();
					min.push(num);
					max.push(temp);
				}
				else
					max.push(num);
			}
		}
		cout << max.top() << '\n';
	}
	return 0;
}