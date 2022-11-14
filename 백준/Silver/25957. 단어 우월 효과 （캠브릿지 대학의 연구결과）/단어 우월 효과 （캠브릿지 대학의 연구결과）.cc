#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map <string, string> m;
int N, M;
string x;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		string temp = x;
		if (x.length() >= 3)
			sort(temp.begin() + 1, temp.end() - 1);
		m[temp] = x;
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> x;
		if (x.length() >= 3)
			sort(x.begin() + 1, x.end() - 1);
		cout << m[x] << ' ';
	}

	return 0;
}