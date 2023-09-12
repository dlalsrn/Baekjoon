#include <iostream>
using namespace std;

int A, B, K, X;

int main(void)
{
	cin >> A >> B >> K >> X;

	if (K + X < A || K - X > B)
		cout << "IMPOSSIBLE";
	else
		cout << min(B, K + X) - max(A, K - X) + 1;

	return 0;
}