#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    sort(array.begin(), array.end());
    answer = array.end() - upper_bound(array.begin(), array.end(), height);
    return answer;
}