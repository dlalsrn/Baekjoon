#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	queue <int> q;
	int N, K, num;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		q.push(i + 1);

	cout << "<";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K-1; j++)
		{
			num = q.front();
			q.pop();
			q.push(num);
		}
		num = q.front();
		q.pop();
		cout << num;
		if (i == N - 1)
			break;
		cout << ", ";
	}
	cout << ">";
	return 0;
}