#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

priority_queue <pi, vector<pi>, greater<pi>> pq;
int N, x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x) pq.push(make_pair(abs(x), x));
		else
		{
			if (pq.empty()) cout << "0\n";
			else
			{
				cout << pq.top().second << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}