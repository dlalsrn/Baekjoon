#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector <int> v;
	priority_queue <int, vector<int>, greater<int>> q;
	int N, K, num;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < K; i++)
		q.push(v[i]);
	for (int i = 0; i < N - K; i++)
	{
		q.push(v[K + i]);
		cout << q.top() << ' ';
		q.pop();
	}
	while (!q.empty())
	{
		cout << q.top() << ' ';
		q.pop();
	}
	return 0;
}