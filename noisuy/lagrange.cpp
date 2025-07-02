#include<bits/stdc++.h>

using namespace std;

typedef struct {
    double x,y;
} diem;

void nhap(int *n, diem **d ) {
    cout << "Nhap so diem: ";
    cin >> *n;
    *d = (diem*)malloc((*n) * sizeof(diem));
    for (int i = 0; i < *n; i++) {
        cout << "Nhap diem thu " << i + 1 << ": ";
        cin >> (*d)[i].x >> (*d)[i].y;
    }
}

void noisuy( int n, diem *d ) {
    double x0;
    cout << "Nhap gia tri x can noi suy: ";
    cin >> x0;
    double res = 0.0;
    //duyệt từng điểm
    for ( int i = 0 ; i < n ; i++ ) {
        double term = d[i].y; //bat dau voi he so y[i]
         // Tinh L_i(x) = tich cac (x - x_j) / (x_i - x_j) voi j # i
        for ( int j = 0 ; j < n ; j++ ) {
            if ( i != j ) {
                term *= (x0 - d[j].x) / (d[i].x - d[j].x);
            }
        }
        res+= term; //cong don thuc L_i(x) vao ket qua
    }
    cout << "Gia tri noi suy tai x = " << x0 << " la: " << res << endl;
}

int main() {
    diem *d;
    int n;
    nhap(&n, &d);
    noisuy(n, d);
    free(d);
    return 0;
}