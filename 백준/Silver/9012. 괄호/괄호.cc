#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	int N, cnt;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		stack <char> st;
		cnt = 0;
		string a;
		cin >> a;
		for (int s = 0; s < a.size(); s++)
		{
			if (a.c_str()[s] == '(')
			{
				cnt++;
				st.push('(');
			}
			else
			{
				cnt--;
				if (cnt < 0)
					break;
				st.pop();
			}
		}
		if (st.empty() && cnt == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
    return 0;
}