#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v = {
    {1, 2, 3, 4, 5, 1, 2, 3, 4, 5},
    {2, 1, 2, 3, 2, 4, 2, 5},
    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
};

vector<int> correct(3, 0);

vector<int> solution(vector<int> answers)
{
    vector<int> answer;

    for (int i = 0; i < answers.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j][i % v[j].size()] == answers[i])
            {
                correct[j]++;
            }
        }
    }

    int mx = *max_element(correct.begin(), correct.end());

    for (int i = 0; i < correct.size(); i++)
    {
        if (correct[i] == mx)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}