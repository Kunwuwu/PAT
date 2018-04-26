#include <cstdio>
#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

ll gcd(ll a, ll b) {                                      /* 辗转相除法 */
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll n;

int main() {
    cin >> n;
    ll a = 0, b = 1;
    while (n--) {
        ll ta, tb, suma, sumb;
        scanf("%lld/%lld", &ta, &tb);
        sumb = tb * b / gcd(tb, b);                     /* 确定通分分母并化简 */
        suma = a * (sumb / b) + ta * (sumb / tb);       /* 确定分子 */
        ll tgcd = gcd(suma, sumb);                      /* 化简分母分子 */
        a = suma / tgcd;
        b = sumb / tgcd;
    }
    ll intp = a / b;
    ll top = a - intp * b;
    if (intp != 0)
        printf("%lld", intp);
    if (intp != 0 && top != 0) printf(" ");
    if (top != 0)
        printf("%lld/%lld", top, b);
    if (intp == 0 && top == 0)
        printf("0");
    return 0;
}
