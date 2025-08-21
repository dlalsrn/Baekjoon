#include <string>
#include <vector>
#include <utility>
using namespace std;

vector<int> solution(vector<string> wallpaper)
{
    vector<int> answer;
    vector<vector<char>> screen;
    pair<int, int> start = { 2501, 2501 };
    pair<int, int> end = { -1, -1 };

    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (int j = 0; j < wallpaper[i].size(); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                start = { min(start.first, i), min(start.second, j) };
                end = { max(end.first, i + 1), max(end.second, j + 1) };
            }
        }
    }

    answer.push_back(start.first);
    answer.push_back(start.second);
    answer.push_back(end.first);
    answer.push_back(end.second);

    return answer;
}