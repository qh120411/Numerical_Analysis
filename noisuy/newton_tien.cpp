#include <bits/stdc++.h>
using namespace std;

typedef struct {
    double x, y;
} diem;

void nhap(int *n, diem **d) {
    cout << "Nhap so diem: ";
    cin >> *n;
    *d = (diem*)malloc((*n) * sizeof(diem));
    for (int i = 0; i < *n; i++) {
        cout << "Nhap diem thu " << i + 1 << ": ";
        cin >> (*d)[i].x >> (*d)[i].y;
    }
}

void noiSuyNewtonTien(int n, diem *d) {
    double h = d[1].x - d[0].x;
    double x0;
    cout << "Nhap gia tri x can noi suy: ";
    cin >> x0;

    // Cấp phát bảng sai phân cấp phát động
    double **D = new double*[n];
    for (int i = 0; i < n; i++) {
        D[i] = new double[n];
        D[i][0] = d[i].y; // Khởi tạo cột đầu tiên là y[i]
    }

    // Tính sai phân tiến
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            D[i][j] = (D[i + 1][j - 1] - D[i][j - 1]) / h;
        }
    }

    // Tính t và giá trị nội suy
    double t = (x0 - d[0].x) / h;
    double result = D[0][0];
    double t_term = 1;

    for (int j = 1; j < n; j++) {
        t_term *= (t - j + 1) / j;//lui thì t+j
        result += t_term * D[0][j];
    }

    cout << "Gia tri noi suy tai x = " << x0 << " la: " << result << endl;

    // Giải phóng bộ nhớ
    for (int i = 0; i < n; i++) {
        delete[] D[i];
    }
    delete[] D;
}

int main() {
    diem *d;
    int n;
    nhap(&n, &d);
    noiSuyNewtonTien(n, d);
    free(d);
    return 0;
}
