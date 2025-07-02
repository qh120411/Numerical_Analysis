#include<bits/stdc++.h>

using namespace std;

double f(double x) {
    return 1/2 * sqrt(10 - x*x*x);
}

int main() {
    double x1, x0, k, err, saiso;
    cin >> x0 >> k >> err;
    cout << fixed << setprecision(6);
    do {
        x1 = f(x0);
        saiso = abs(x1-x0);
        x1 = x0;
        
    } while ( saiso > err*(1-k)/k);
    cout << fixed << setprecision(6) << "Nghiem gan dung la: " << x1 << endl;
}