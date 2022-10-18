#include <iostream>
using namespace std;

int main(void)
{
	int N, num, sum = 0;
	string first;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		sum ^= num - 2;
	}
	cin >> first;
	if (first == "Whiteking")
	{
		if (sum)
			cout << "Whiteking";
		else
			cout << "Blackking";
	}
	else
	{
		if (sum)
			cout << "Blackking";
		else
			cout << "Whiteking";
	}
	return 0;
}