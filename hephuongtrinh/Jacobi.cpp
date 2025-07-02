#include<bits/stdc++.h>

using namespace std;

int main() {
    double a[4][4] = {
        {10, -1, 2, -3},
        {1, 10, -1, 2},
        {2, 3, 20, -1},
        {3, 2, 1, 20}
    };
    double b[4] = {0, 5, -10, 15};
    int n = 4;

    double x[n] = {0}, x_moi[n];

    double eps;
    cout << "Nhap vao sai so epsiolon: ";
    cin >> eps;

    int max_it = 100, it = 0;

    do {
        for ( int i = 0 ; i < n ; i++ ) {
            double sum = b[i];
            for ( int j = 0 ; j < n ; j++ ) {
                if ( i != j) {
                    sum -= a[i][j] * x[j];
                }
            }
            x_moi[i] = sum / a[i][i];
        }
        // Kiểm tra sai số
        double max_err = 0;
        for (int i = 0; i < n; i++) {
            max_err = max(max_err, fabs(x_moi[i] - x[i]));
            x[i] = x_moi[i];
        }

        it++;
        if (max_err < eps)
            break;

    }while(it < max_it);
    cout << "\n Nghiem gan dung sau " << it << " lan la la: "<<'\n';
    for ( int i = 0 ; i < n ; i++ ) {
        cout << fixed << setprecision(6) << x[i] << '\n';
    }
}