#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	set <string> s;
	int N, M, cnt = 0;
	string x;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		s.insert(x);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> x;
		if (s.find(x) != s.end())
			cnt++;
	}
	cout << cnt;
	return 0;
}