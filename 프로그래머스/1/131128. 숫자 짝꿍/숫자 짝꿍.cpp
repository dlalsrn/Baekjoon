#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y)
{
    string answer = "";
    vector<string> v;
    vector<int> cntX(10, 0);
    vector<int> cntY(10, 0);

    for (int i = 0; i < X.size(); i++) cntX[X[i] - '0']++;
    for (int i = 0; i < Y.size(); i++) cntY[Y[i] - '0']++;

    for (int i = 0; i < 10; i++)
    {
        int mn = min(cntX[i], cntY[i]);

        for (int j = 0; j < mn; j++) v.push_back(to_string(i));
    }

    sort(v.begin(), v.end(), greater<>());

    if (v.size() == 0) answer = "-1";
    else if (v[0] == "0") answer = "0";
    else
    {
        for (string& x : v) answer += x;
    }

    return answer;
}