#include <iostream>
using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	cout << (N % 3 ? 1 : 0);

	return 0;
}