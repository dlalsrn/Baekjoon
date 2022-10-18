#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector <int> v(20000000, 0);
	int N, M, num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v[10000000+num]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		cout << v[10000000+num] << ' ';
	}
	return 0;
}