// 팰린드롬수
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	string a, b;
	cin >> a;
	while (a != "0")
	{
		b = a;
		reverse(a.begin(), a.end());
		if (a == b)
			cout << "yes\n";
		else
			cout << "no\n";
		cin >> a;
	}
	return 0;
}