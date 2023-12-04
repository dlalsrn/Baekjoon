#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string x;
int cnt;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin.ignore();

	while (true)
	{
		getline(cin, x);
		cnt = 0;
		
		if (x == "#")
			break;

		transform(x.begin(), x.end(), x.begin(), ::tolower);
		
		for (int i = 0; i < x.size(); i++)
			if (x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o' || x[i] == 'u')
				cnt++;


		cout << cnt << '\n';
	}

	return 0;
}