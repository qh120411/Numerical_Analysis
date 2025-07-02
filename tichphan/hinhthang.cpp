#include<bits/stdc++.h>

using namespace std;

#define f(x) ( ( x * atan(x) ) / ( 5 * x * x + 10)  )

double hinhthang ( double a, double b, double n) {
    double h = (b - a) / n;
    double S = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        S += 2 * f(x);
    }
    S = S * h / 2;
    return S;
}

int main() {
    double a, b, n;
    cin >> a >> b >> n;
    double res = hinhthang(a, b, n);
    cout << fixed << setprecision(6) << res << endl;
    return 0;
}