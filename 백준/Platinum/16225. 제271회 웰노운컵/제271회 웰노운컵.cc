#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long sum = 0;
	int N;
	cin >> N;
	vector <pair<int, int>> v(N + 1);
	priority_queue <pi, vector<pi>, greater<pi>> q;
	priority_queue <pi> A; // 2*i+1 개의 문제를 담는 queue
	for (int i = 1; i <= N; i++)
		cin >> v[i].first;
	for (int i = 1; i <= N; i++)
		cin >> v[i].second;
	for (int i = 1; i <= N; i++)
		q.push(make_pair(v[i].second, v[i].first));

	sum += q.top().second;
	q.pop();
	for (int i = 1; i + 1 < N; i += 2)
	{
		A.push(make_pair(q.top().second, q.top().first));
		q.pop();
		A.push(make_pair(q.top().second, q.top().first));
		q.pop();
		sum += A.top().first;
		A.pop();
	}
	cout << sum;
	return 0;
}