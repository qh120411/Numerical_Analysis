#include<bits/stdc++.h>

using namespace std;

double f(double x) {
    return x * x * x - x - 1;
}

double df(double x) {
    return 3 * x * x - 1;
}

int main() {
    double a,b;
    double err;
    double x0, x1;

    cout << "Nhap khoang [a,b]: ";
    cin >> a >> b;

    cout << "Nhap sai so: ";
    cin >> err;

    x0 = b; // hoac x0 = a
    x1 = x0 - f(x0) / df(x0);

    while (fabs(x1 - x0) > err) {
        x0 = x1;
        x1 = x0 - f(x0) / df(x0);
    }

    cout << "x = " << x1 << endl;

    return 0;
}