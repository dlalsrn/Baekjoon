#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int sz = numbers.size();
    sort(numbers.begin(), numbers.end());
    return answer = numbers[sz - 2] * numbers[sz - 1];
}