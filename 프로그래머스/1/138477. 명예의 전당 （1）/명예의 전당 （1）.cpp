#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;
    vector<int> honor;

    for (int i = 0; i < score.size(); i++)
    {
        honor.push_back(score[i]);
        sort(honor.begin(), honor.end());
        
        answer.push_back((honor.size() < k ? honor[0] : honor[honor.size() - k]));
    }
    return answer;
}