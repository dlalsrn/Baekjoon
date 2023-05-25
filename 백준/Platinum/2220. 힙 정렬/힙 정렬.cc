#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int N;

int main(void)
{
	cin >> N;
	v.resize(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		int n = i;
		v[i] = 1;
		v[1] = i;
		if (i == N)
			break;
		while (v[1] != 1)
		{
			swap(v[n], v[n / 2]);
			n /= 2;
		}
	}

	for (int i = 1; i <= N; i++)
		cout << v[i] << ' ';

	return 0;
}