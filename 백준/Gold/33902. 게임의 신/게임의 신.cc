#include <bits/stdc++.h>
using namespace std;

int X;
int Y;
vector <bool> ans;

int gdc(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    if (a < b) 
    {
        swap(a, b);
    }
    
    return gcd(b, a % b);
}

int main(void)
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> X >> Y;

    ans.resize(Y, false);

    // i와 j가 서로소일 때, X가 j일 때의 결과에 따라 X가 i일 때의 답이 정해짐
    // 예를 들어, X가 j일 때 [j + 1, Y] 사이에 서로소가 없다고 가정
    // 위 조건에서 i와 j가 서로소일 때, X가 j면 지므로 X가 i인 턴에는 무조건 이김
    // ans[j] = true => X가 j일 때 진다는 의미

    ans[Y] = true; // X가 Y일 때는 무조건 짐
    for (int i = Y - 1; i >= X; i--)
    {
        for (int j = i + 1; j <= Y; j++)
        {
            if (gcd(i, j) == 1)
            {
                // ans[j]가 true인 j가 하나라도 존재하면 X가 i일 때 공격턴인 사람은 무조건 이김
                ans[i] = ans[i] || ans[j]; 
            }
        }
        
        // ans[i]가 true라는 것은 이기는 수가 존재한다는 뜻
        // 즉, i보다 작은 임의의 수 N이 i와 서로소라고 할 때 i를 선택하면 진다는 의미
        ans[i] = !ans[i];
    }

    cout << (ans[X] ? "putdata" : "khj20006");

    return 0;
}