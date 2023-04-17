#include <iostream>
using namespace std;
typedef long long ll;

ll K, cnt = 0;

int main(void)
{
	cin >> K;
	if (!(K % 9 == 0 || K % 9 == 1))
		cout << -1;
	else
		cout << "1\n2\n3";

	return 0;
}