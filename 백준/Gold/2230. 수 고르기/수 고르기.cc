#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
int main() {
    int n, m, a[100000], r = 2e9;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    int i = 0, j = 0;
    while (j < n) {
        if (a[j] - a[i] < m) j++;
        else r = min(r, a[j] - a[i++]);
    }
    printf("%d", r);
    return 0;
}