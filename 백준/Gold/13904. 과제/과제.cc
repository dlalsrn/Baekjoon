#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
	priority_queue <pair<int, int>> q;
	int N, sum = 0;
	pair<int, int> temp;
	cin >> N;
	vector <int> v(1001, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> temp.second >> temp.first;
		q.push(temp);
	}

	for (int i = 0; i < N; i++)
	{
		temp = q.top();
		q.pop();
		if (v[temp.second] == 0)
		{
			v[temp.second] = temp.first;
			sum += v[temp.second];
		}
		else
		{
			while (temp.second != 0 && v[temp.second])
				temp.second--;
			if (temp.second != 0)
			{
				v[temp.second] = temp.first;
				sum += v[temp.second];
			}
		}
	}
	cout << sum;
	return 0;
}