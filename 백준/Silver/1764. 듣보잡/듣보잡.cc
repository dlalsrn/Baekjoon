#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map <string, int> m;
vector <string> v;
string x;
int N, M;

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N + M; i++)
	{
		cin >> x;
		if (++m[x] == 2)
			v.push_back(x);
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';

	return 0;
}