#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, cnt;
string x;
vector <int> v(76, 0);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin.ignore();
		getline(cin, x);
		cnt = 1;
		for (int j = 0; j < x.size() - 1; j++)
			if (x[j] == ' ' && x[j+1] != ' ')
				cnt++;
		v[cnt]++;
	}

	for (int i = 0; i <= 75; i++)
		if (v[i])
			cout << i << ' ' << v[i] << '\n';

	return 0;
}