#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	set <pair<int, int>> s;
	map <int, int> m;
	int N, M, number, rank;
	string com;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> number >> rank;
		m[number] = rank;
		s.insert(make_pair(rank, number));
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> com;
		if (com == "recommend")
		{
			cin >> number;
			if (number == -1)
			{
				auto it = s.begin();
				cout << (*it).second << '\n';
			}
			else
			{
				auto it = s.end();
				cout << (*(--it)).second << '\n';
			}
		}
		else if (com == "add")
		{
			cin >> number >> rank;
			m[number] = rank;
			s.insert(make_pair(rank, number));
		}
		else
		{
			cin >> number;
			s.erase({ m[number], number });
		}
	}
}