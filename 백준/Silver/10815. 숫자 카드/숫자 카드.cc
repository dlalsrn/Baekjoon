#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	set <int> s;
	int N, M, num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		s.insert(num);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		if (s.find(num) != s.end())
			cout << 1 << ' ';
		else
			cout << 0 << ' ';
	}
	return 0;
}