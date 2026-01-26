#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int left = 0;
    for (int i = 0; i < stations.size(); i++)
    {
        int station = stations[i];
        int start = station - w - 1;
        int end = station + w - 1;

        if (left < start)
        {
            int dist = start - left;
            answer += dist / (2 * w + 1);

            if (dist % (2 * w + 1) != 0)
            {
                answer++;
            }
        }

        left = end + 1;
	}

    if (n > left)
    {
	    answer += (n - left) / (2 * w + 1);
        if ((n - left) % (2 * w + 1) != 0)
        {
            answer++;
		}
    }

    return answer;
}