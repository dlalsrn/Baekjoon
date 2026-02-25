#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int cnt = 0;
vector<int> A, B;
vector<int> answerA, answerB;
vector<int> tempA, tempB;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		A.emplace_back(x);
	}

	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		B.emplace_back(x);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	while (!A.empty() && !B.empty())
	{
		if (A.back() == B.back())
		{
			++cnt;
			answerA.emplace_back(A.back());
			answerB.emplace_back(B.back());
			A.pop_back();
			B.pop_back();
		}
		else if (A.back() > B.back())
		{
			tempA.emplace_back(A.back());
			A.pop_back();
		}
		else
		{
			tempB.emplace_back(B.back());
			B.pop_back();
		}
	}

	while (!A.empty())
	{
		answerA.emplace_back(A.back());
		A.pop_back();
	}
	while (!tempA.empty())
	{
		answerA.emplace_back(tempA.back());
		tempA.pop_back();
	}

	while (!B.empty())
	{
		answerB.emplace_back(B.back());
		B.pop_back();
	}
	while (!tempB.empty())
	{
		answerB.emplace_back(tempB.back());
		tempB.pop_back();
	}

	cout << cnt << '\n';
	for (int i = 0; i < answerA.size(); ++i) cout << answerA[i] << ' ';
	cout << '\n';
	for (int i = 0; i < answerB.size(); ++i) cout << answerB[i] << ' ';

	return 0;
}