#include<bits/stdc++.h>

using namespace std;

double f( double x ) {
    return x*x*x - x - 1;
}

double chiadoi( double a, double b, double epsilon) {
    
    if ( f(a) * f(b) >= 0 ) {
        cout << "Khong giai duoc phuong trinh" << endl;
    }
    double c;
    double saiso;
    int it = 1;
    do {
        c = ( a + b ) / 2;
        saiso = abs( b - a );
        if ( f(c) == 0 ) {
            break;
        }
        else if ( f(c) * f(a) < 0 ) {
            b = c;
        }
        else {
            a = c;
        }
        it++;
        cout << "Lan lap: " << it << '\t' << " x = " << c << '\t' << " f(x) = " << f(c) << '\t' << " sai so = " << saiso << endl;
    } while ( saiso >= epsilon );
    return c;
}

int main() {
    double a,b,epsilon;
    cout << "Nhap a, b, epsilon: ";
    cin >> a >> b >> epsilon;
    double res = chiadoi(a,b,epsilon);
    cout << "Nghiem cua phuong trinh la: " << res << endl;
}