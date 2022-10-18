#include <iostream>
using namespace std;

int main(void)
{
	int N, num;
	long long sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		sum ^= num;
	}
	if (sum)
		cout << "koosaga";
	else
		cout << "cubelover";
	return 0;
}