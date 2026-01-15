#include <string>
#include <map>
#include <utility>
using namespace std;
using pi3 = pair<pair<int, int>, char>;

int solution(string dirs)
{
    int answer = 0;

    int mx = 10;
    pair<int, int> curPoint = { 5,5 };

    map<pi3, bool> m;

    for (int i = 0; i < dirs.size(); ++i)
    {
        int yy = curPoint.first;
        int xx = curPoint.second;
        char oppositeDir;

        if (dirs[i] == 'L')
        {
            --xx;
            oppositeDir = 'R';
        }
        else if (dirs[i] == 'R')
        {
            ++xx;
            oppositeDir = 'L';
        }
        else if (dirs[i] == 'U')
        {
            --yy;
            oppositeDir = 'D';
        }
        else if (dirs[i] == 'D')
        {
            ++yy;
            oppositeDir = 'U';
        }

        if (xx < 0 || xx > mx || yy < 0 || yy > mx) continue;

        if (!m[make_pair(curPoint, dirs[i])])
        {
            m[make_pair(curPoint, dirs[i])] = true;
            m[make_pair(make_pair(yy, xx), oppositeDir)] = true;
            answer++;
        }

        curPoint = { yy, xx };
    }

    return answer;
}