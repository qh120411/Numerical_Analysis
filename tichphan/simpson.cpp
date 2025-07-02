#include<bits/stdc++.h>

using namespace std;

#define f(x) (exp(x*x));

double simpson( double a, double b, double n) {
    double h = (b - a) / n;
    double S = f(a) + f(b);
    for ( int i = 1 ; i < n-1 ; i++ ) {
        double x = a + i * h ;
        S += 2 * f(x);
        if ( i % 2 == 0 ) {
            S += 2 * f(x);
        }
    }
    S = S * h / 3;
    return S;
}

int main() {
    double a, b, n;
    cin >> a >> b >> n;
    double res = simpson(a, b, n);
    cout << fixed << setprecision(6) << res << endl;
    return 0;
}