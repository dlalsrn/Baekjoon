#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <iostream>
using namespace std;
using tp = tuple<int, int, int, int>;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
char dir[] = { 'R', 'D', 'L', 'U' };

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int n = board.size();

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    vector<vector<vector<int>>> check =
        vector<vector<vector<int>>>(n,
            vector<vector<int>>(n,
                vector<int>(4, 1000000)));

    pq.push(make_tuple(0, 0, 0, -1)); // price, y, x, prevDir
    check[0][0][0] = 0;
    check[0][0][1] = 0;
    check[0][0][2] = 0;
    check[0][0][3] = 0;

    while (!pq.empty())
    {
        auto [total, y, x, prevDir] = pq.top();
        pq.pop();

        if (y == n - 1 && x == n - 1)
        {
            answer = total;
            break;
        }

        for (int k = 0; k < 4; ++k)
        {
            int yy = y + dy[k];
            int xx = x + dx[k];

            if (yy < 0 || yy >= n || xx < 0 || xx >= n || board[yy][xx] == 1) continue;

            int nextPrice = total + 100;
            if ((y != 0 || x != 0) && prevDir != k)
            {
                nextPrice += 500;
            }

            if (check[yy][xx][k] > nextPrice) 
            {
                check[yy][xx][k] = nextPrice;
                pq.push({ nextPrice, yy, xx, k });
            }
        }
    }

    return answer;
}