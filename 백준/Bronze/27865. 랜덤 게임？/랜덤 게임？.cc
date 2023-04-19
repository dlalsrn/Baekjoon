#include <iostream>
using namespace std;

int N;
char x;

int main(void)
{
	cin >> N;

	do
	{
		cout << "? " << 1 << endl;
		cin >> x;
	} while (x == 'N');
	cout << "! " << 1 << endl;
	return 0;
}