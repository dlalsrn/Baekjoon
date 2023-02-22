// 이 사람 왜 이렇게 1122를 좋아함?
// 22.12.22
#include <iostream>
#define inf 1000000000000000000
using namespace std;

typedef long long ll;
ll Q, a, mx = inf + 1, mn = -(inf + 1);
string b;
int index = 0, ch = 0;
bool TF = false;

int main(void)
{
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> a >> b;
		if (b == "^")
			mn = max(mn, a);
		else
			mx = min(mx, a);
		if (mx - mn <= 1)
		{
			if (ch == 1)
				continue;
			index = i + 1;
			ch = 1;
		}
		else if (mx - mn == 2)
		{
			if (ch != 0)
				continue;
			index = i + 1;
			ch = 2;
		}
	}

	if (ch == 0)
		cout << "Hmm...";
	else if (ch == 1)
		cout << "Paradox!\n" << index;
	else
		cout << "I got it!\n" << index;

	return 0;
}