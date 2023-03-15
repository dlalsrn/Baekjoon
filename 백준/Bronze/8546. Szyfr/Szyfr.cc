#include <iostream>
#include <vector>
using namespace std;

vector <int> v(10000001);

int main(void)
{
	int a, b;
	cin >> a >> b;
	v[1] = 1;
	v[2] = 1;
	for (int i = 3; i <= 10000000; i++)
		v[i] = (v[i - 1] + v[i - 2]) % 10;

	for (int i = a; i <= b; i++)
		cout << v[i];

	return 0;
}