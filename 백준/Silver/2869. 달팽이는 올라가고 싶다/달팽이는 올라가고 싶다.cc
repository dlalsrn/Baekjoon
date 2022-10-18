// 달팽이는 올라가고 싶다
#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int A, B, V;
	cin >> A >> B >> V;
	if (A >= V)
		cout << 1;
	else
	{
		int cnt = ceil((double)(V - A) / (A - B)) + 1;
		cout << cnt;
	}
	return 0;
}