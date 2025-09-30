// 양궁대회
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

int maxScore = 0;
vector<int> answer = { -1 };

pair<int, int> sumLionScore(vector<int>& apeach, vector<int>& lion)
{
	int sumApeach = 0;
	int sumLion = 0;

	for (int i = 0; i < apeach.size(); i++)
	{
		if (apeach[i] > lion[i])
		{
			sumApeach += 10 - i;
		}
		else if (apeach[i] < lion[i])
		{
			sumLion += 10 - i;
		}
	}

	return { sumApeach, sumLion };
}

void FindMaxScore(int n, vector<int>& info, int index, vector<int>& result)
{
	if (index == info.size() - 1)
	{
		pair<int, int> score = sumLionScore(info, result);
		int apeachScore = score.first;
		int lionScore = score.second;
		int diff = lionScore - apeachScore;
		result[10] = n;

		if (maxScore < diff)
		{
			maxScore = diff;
			answer = result;
		}
		else if (maxScore != 0 && maxScore == diff)
		{
			for (int i = result.size() - 1; i >= 0; i--)
			{
				if (answer[i] < result[i])
				{
					answer = result;
					break;
				}
				else if (answer[i] > result[i])
				{
					break;
				}
			}
		}

		return;
	}

	for (int i = index; i < info.size() - 1; i++)
	{
		if (n >= info[i] + 1)
		{
			result[i] = info[i] + 1;
			FindMaxScore(n - (info[i] + 1), info, i + 1, result);
		}

		result[i] = 0;
		FindMaxScore(n, info, i + 1, result);
	}
}

vector<int> solution(int n, vector<int> info)
{
	vector<int> result = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	FindMaxScore(n, info, 0, result);

	return answer;
}
