#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems)
{
	unordered_map<string, int> gemSet;
	int minLength;
	int minLeft, minRight;

	set<string> s;
	int totalGemNum;
	for (int i = 0; i < gems.size(); ++i)
	{
		s.insert(gems[i]);
	}

	totalGemNum = s.size();

	int curGemNum = 0;
	int left = 0;
	int right = 0;

	minLength = gems.size();
	minLeft = 1, minRight = gems.size();

	while (right < gems.size())
	{
		if (gemSet[gems[right]] == 0)
		{
			++curGemNum;
		}

		++gemSet[gems[right]];

		while (curGemNum == totalGemNum)
		{
			if (minLength > right - left)
			{
				minLength = right - left;
				minLeft = left + 1;
				minRight = right + 1;
			}

			if (gemSet[gems[left]] == 1)
			{
				--curGemNum;
			}

			--gemSet[gems[left]];
			++left;
		}

		++right;
	}

	return { minLeft, minRight };
}