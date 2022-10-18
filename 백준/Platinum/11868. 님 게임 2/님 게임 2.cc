#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, num, sum = 0;
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