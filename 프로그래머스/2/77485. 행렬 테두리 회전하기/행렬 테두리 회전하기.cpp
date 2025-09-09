#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Rotate(vector<vector<int>>& v, int y1, int y2, int x1, int x2)
{
    int n = v[y1][x1];
    int mn = n;

    for (int i = y1; i < y2; i++)
    {
        v[i][x1] = v[i + 1][x1];
        mn = min(mn, v[i][x1]);
    }

    for (int i = x1; i < x2; i++)
    {
        v[y2][i] = v[y2][i + 1];
        mn = min(mn, v[y2][i]);
    }

    for (int i = y2; i > y1; i--)
    {
        v[i][x2] = v[i - 1][x2];
        mn = min(mn, v[i][x2]);
    }

    for (int i = x2; i > x1 + 1; i--)
    {
        v[y1][i] = v[y1][i - 1];
        mn = min(mn, v[y1][i]);
    }
    
    v[y1][x1 + 1] = n;

    return mn;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> v(rows, vector<int>(columns));

    int index = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            v[i][j] = index++;
        }
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int y1 = queries[i][0] - 1;
        int x1 = queries[i][1] - 1;
        int y2 = queries[i][2] - 1;
        int x2 = queries[i][3] - 1;

        answer.push_back(Rotate(v, y1, y2, x1, x2));
    }

    return answer;
}
