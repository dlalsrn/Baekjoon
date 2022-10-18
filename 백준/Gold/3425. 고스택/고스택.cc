#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;

ll abc(ll a)
{
	return a < 0 ? -a : a;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector <pair<string, ll>> v;
	ll num;
	string C;
	bool TF;
	while (true)
	{
		cin >> C;
		if (C == "QUIT")
			break;
		else if (C == "NUM")
		{
			cin >> num;
			v.push_back({ C, num });
		}
		else if (C == "END")
		{
			ll N;
			cin >> N;
			for (int i = 0; i < N; i++)
			{
				
				TF = false;
				stack <ll> s;
				cin >> num;
				s.push(num);
				for (int j = 0; j < v.size(); j++)
				{
					if (v[j].first == "NUM")
						s.push(v[j].second);
					else if (v[j].first == "POP")
					{
						if (s.empty())
						{
							cout << "ERROR\n";
							TF = true;
							break;
						}
						else
							s.pop();
					}
					else if (v[j].first == "INV")
					{
						if (s.empty())
						{
							cout << "ERROR\n";
							TF = true;
							break;
						}
						else
							s.top() *= (-1);
					}
					else if (v[j].first == "DUP")
					{
						if (s.empty())
						{
							cout << "ERROR\n";
							TF = true;
							break;
						}
						else
							s.push(s.top());
					}
					else if (v[j].first == "SWP")
					{
						if (s.size() < 2)
						{
							cout << "ERROR\n";
							TF = true;
							break;
						}
						else
						{
							ll a = s.top();
							s.pop();
							ll b = s.top();
							s.pop();
							s.push(a);
							s.push(b);
						}
					}
					else if (v[j].first == "ADD")
					{
						if (s.size() < 2)
						{
							cout << "ERROR\n";
							TF = true;
							break;
						}
						else
						{
							ll a = s.top();
							s.pop();
							ll b = s.top();
							s.pop();
							if (abc(a + b) > 1000000000)
							{
								cout << "ERROR\n";
								TF = true;
								break;
							}
							else
								s.push(a+b);
						}
					}
					else if (v[j].first == "SUB")
					{
						if (s.size() < 2)
						{
							cout << "ERROR\n";
							TF = true;
							break;
						}
						else
						{
							ll a = s.top();
							s.pop();
							ll b = s.top();
							s.pop();
							if (abc(b - a) > 1000000000)
							{
								cout << "ERROR\n";
								TF = true;
								break;
							}
							else
								s.push(b - a);
						}
					}
					else if (v[j].first == "MUL")
					{
						if (s.size() < 2)
						{
							cout << "ERROR\n";
							TF = true;
							break;
						}
						else
						{
							ll a = s.top();
							s.pop();
							ll b = s.top();
							s.pop();
							if (abc(a * b) > 1000000000)
							{
								cout << "ERROR\n";
								TF = true;
								break;
							}
							else
								s.push(a * b);
						}
					}
					else if (v[j].first == "DIV")
					{
						if (s.size() < 2)
						{
							cout << "ERROR\n";
							TF = true;
							break;
						}
						else
						{
							ll a = s.top();
							s.pop();
							ll b = s.top();
							s.pop();
							if (a == 0)
							{
								cout << "ERROR\n";
								TF = true;
								break;
							}
							else
								s.push(b / a);
						}
					}
					else if (v[j].first == "MOD")
					{
						if (s.size() < 2)
						{
							cout << "ERROR\n";
							TF = true;
							break;
						}
						else
						{
							ll a = s.top();
							s.pop();
							ll b = s.top();
							s.pop();
							if (a == 0)
							{
								cout << "ERROR\n";
								TF = true;
								break;
							}
							else
								s.push(b % a);
						}
					}
				}
				if (!TF && s.size() == 1)
					cout << s.top() << '\n';
				else if (!TF && s.size() != 1)
					cout << "ERROR\n";
			}
			cout << '\n';
			v.clear();
			vector <pair<string, ll>>().swap(v);
		}
		else
			v.push_back({ C, 0 });
	}
}