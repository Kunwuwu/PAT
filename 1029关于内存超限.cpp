#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define ll long long

using namespace std;

const int MAX = 99999999;

int main() {
    vector<int> a;
    int n, m;
    cin >> n;
    a.resize(n);
    long t;
    for (int i = 0; i < a.size(); i++) {
        scanf("%ld", &t);
        a[i] = min((long)MAX, t);
    }
    cin >> m;
    int i = 0, j = 0;
    int temp;
    scanf("%d", &temp);
    while (i != n || j != m) {
        if (a[i] < temp) {
            if (i + j == (n + m + 1) / 2 - 1) {
                printf("%d", a[i]);
                break;
            }
            i++;
        } else {
            if (i + j == (n + m + 1) / 2 - 1) {
                printf("%d", temp);
                break;
            }
            j++;
            scanf("%d", &temp);
        }
    }
    return 0;
}
