#include <iostream>
#include <algorithm>
using namespace std;

string x;
int cnt = 0, mx = 0;

int main(void)
{
	cin >> x;
	int cnt = 0;

	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == 'a')
			cnt++;
		else
			cnt = 0;
		mx = max(mx, cnt);
	}

	for (int i = 0; i < mx + 1; i++)
		cout << 'a';

	return 0;
}