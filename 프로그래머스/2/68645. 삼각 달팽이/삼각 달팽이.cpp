#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>> v(n, vector<int>(n, -1));
    int prevY, prevX;
    int index = 1;

    int y = 0, x = 0;
    while (true)
    {
        prevY = y;
        prevX = x;
        while (true)
        {
            v[y][x] = index;
            if (y < n - 1 && v[y + 1][x] == -1)
            {
                y++;
                index++;
            }
            else
            {
                break;
            }
        }
        if (prevY == y && prevX == x)
        {
            break;
        }

        prevY = y;
        prevX = x;
        while (true)
        {
            v[y][x] = index;
            if (x < n - 1 && v[y][x + 1] == -1)
            {
                x++;
                index++;
            }
            else
            {
                break;
            }
        }
        if (prevY == y && prevX == x)
        {
            break;
        }

        prevY = y;
        prevX = x;
        while (true)
        {
            v[y][x] = index;
            if (y > 0 && x > 0 && v[y - 1][x - 1] == -1)
            {
                y--;
                x--;
                index++;
            }
            else
            {
                break;
            }
        }
        if (prevY == y && prevX == x)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == -1)
            {
                break;
            }
            answer.push_back(v[i][j]);
        }
    }

    return answer;
}