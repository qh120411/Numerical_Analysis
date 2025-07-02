#include<bits/stdc++.h>

using namespace std;

#define f(x) ( (x*x*exp(x)) / ( 4 * x * x + 7))

double simpson( double a, double b, double n) {
    double h = (b - a) / n;
    double S = f(a) + f(b);
    for ( int i = 1 ; i < n ; i++ ) {
        double x = a + i * h ;
        S += 2 * f(x);
        if ( i % 2 != 0 ) {
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