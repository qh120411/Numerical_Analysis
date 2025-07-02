#include <bits/stdc++.h>
using namespace std;


vector<double> x = {1.13, 1.27, 1.41, 1.55, 1.69, 1.83, 1.97};
vector<double> fx = {1.3, 1.66, 2.47, 1.86, 2.87, 3.28, 0};

// Hàm g(i) = x[i] * f(x[i])
double g(int i) {
    return x[i] * fx[i];
}

int main() {
    int n = x.size() - 1;
    double h = 0.14;
    double target = 5.0; //kết quá

    // Tính tổng không chứa A
    double S = g(0); // x[0]*fx[0]
    for (int i = 1; i < n; i++) {
        S += 2 * g(i);
    }
    // Thiếu g(n) = x[n] * A ⇒ gọi fx[n] = A
    // target = (h / 2) * (S + x[n] * A)
    // => x[n] * A = (target * 2 / h) - S

    double A = (target * 2 / h - S) / x[n];
    fx[n] = A;

    cout << fixed << setprecision(4);
    cout << "=> Gia tri A can tim la: " << A << endl;

    return 0;
}
